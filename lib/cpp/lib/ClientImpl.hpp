#pragma once
#include <RPConMQ/Client.hpp>
#include "AbstractEndpoint.hpp"


namespace RPConMQ {

class ClientImpl
:	public virtual IClient
,	public AbstractEndpoint
{
private:
	qpid::messaging::Session _session;
public:
	ClientImpl (const std::string& init_data,
				const std::string& service_queue)
	:	AbstractEndpoint(init_data)
	,	_session(createSession())
	{}

	virtual ~ClientImpl ()
	{}

	virtual Message request (const Message& message)
	{
		auto receiver = _abstract.session().createReceiver("#");
		auto responseQueue = receiver.getAddress();
		const auto id = create_correlation_id();

		qpid::messaging::Message request(message);
		request.setReplyTo(responseQueue);
		request.setCorrelationId(id);

		_sender.send(request);
		Message response = receiver.fetch();
		session.acknowledge(response);

		if ( id == response.getCorrelationId())
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
