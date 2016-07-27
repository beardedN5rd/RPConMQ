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
	ClientImpl (	const std::string& init_data,
			const std::string& service_queue)
	:	AbstractEndpoint(init_data)
	,	_session(createSession())
	,	_sender(_session.createSender(service_queue))
	,	_receiver(_session.createReceiver("#"))
	{}

	virtual ~ClientImpl ()
	{}

	virtual Message request (const Message& message)
	{
		const auto responseQueue = receiver.getAddress();
		const auto id = create_correlation_id();

		qpid::messaging::Message request(message);
		request.setReplyTo(responseQueue);
		request.setCorrelationId(id);

		_sender.send(request);
		const auto response = _receiver.fetch();
		std::cout	<< request.getContentObject()
				<< " -> "
				<< response.getContentObject()
				<< std::endl;
		session.acknowledge(response);

		if ( id != response.getCorrelationId())
			return ""; //id mismatch

		return response.getContentObject();
	}

private:
	std::string create_correlation_id ()
	{
		return "unique";
	}

};

}
