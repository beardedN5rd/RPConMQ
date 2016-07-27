#pragma once
#include <RPConMQ/Client.hpp>
#include "AbstractEndpoint.hpp"


namespace RPConMQ {

class ClientImpl
:	public virtual IClient
,	public AbstractEndpoint
{
private:
	qpid::messaging::Session	_session;
	qpid::messaging::Sender		_sender;
	qpid::messaging::Receiver	_receiver;
public:
	ClientImpl (const std::string& init_data,
				const std::string& service_queue)
	:	AbstractEndpoint(init_data)
	,	_session(createSession())
	,	_sender(_session.createSender(service_queue))
	,	_receiver(_session.createReceiver("#"))
	{}

	virtual ~ClientImpl ()
	{}

	virtual Response request (const Request& message)
	{
		const auto responseQueue = _receiver.getAddress();
		const auto id = create_correlation_id();

		qpid::messaging::Message request(message);
		request.setReplyTo(responseQueue);
		request.setCorrelationId(id);

		_sender.send(request);
		const auto response = _receiver.fetch();

		_session.acknowledge(const_cast<qpid::messaging::Message&>(response));

		if ( id != response.getCorrelationId())
			std::cout << "id mismatch" << std::endl;

		return response.getContentObject();
	}

private:
	std::string create_correlation_id ()
	{
		return "unique";
	}

};

}
