#pragma once
#include <RPConMQ/Client.hpp>
#include "AbstractEndpoint.hpp"


namespace RPConMQ {

class ClientImpl
:	public virtual IClient
,	public AbstractEndpoint
{
private:
	CorrelationCallBack			_create_correlation_id;
	qpid::messaging::Session	_session;
	qpid::messaging::Sender		_sender;
	qpid::messaging::Receiver	_receiver;
public:
	ClientImpl (const std::string& init_data,
				const std::string& service_queue,
				const CorrelationCallBack& correlation_callback)
	:	AbstractEndpoint(init_data)
	,	_create_correlation_id(correlation_callback)
	,	_session(createSession())
	,	_sender(_session.createSender(service_queue))
	,	_receiver(_session.createReceiver("#"))
	{}

	virtual ~ClientImpl ()
	{}

	virtual Response request (const Request& message)
	{
		const auto responseQueue = _receiver.getAddress();
		const auto id = _create_correlation_id();

		qpid::messaging::Message request(message);
		request.setReplyTo(responseQueue);
		request.setCorrelationId(id);

		_sender.send(request);
		const auto response = _receiver.fetch();

		_session.acknowledge(const_cast<qpid::messaging::Message&>(response));

		if ( id != response.getCorrelationId())
			throw ConnectionException("id mismatch");
		return response.getContentObject();
	}
};

}
