#pragma once
#include <RPConMQ/Server.hpp>
#include "AbstractEndpoint.hpp"

namespace RPConMQ {

class ServerImpl
:	public virtual IServer
,	public AbstractEndpoint
{
private:
	qpid::messaging::Session	_session;
	qpid::messaging::Sender		_sender;
	qpid::messaging::Receiver	_receiver;

	void process(const qpid::messaging::Message& request)
	{
		const auto& address = request.getReplyTo();
		if (address)
			respond(request, address);
		else
		{
			std::cerr	<< "Error: no reply address specified for request: "
					<< request.getContent()
					<< std::endl;
			session.reject(request);
		}
	}

	void respond(	const qpid::messaging::Message& request,
			const qpid::messaging::Address& address)
	{
			Sender sender = session.createSender(address);
			Message response;

			qpid::types::Variant requestObj = request.getContentObject();
			if (requestObj.getType() == qpid::types::VAR_STRING)
			{
				std::string s = requestObj;
				std::transform(s.begin(), s.end(), s.begin(), toupper);
				qpid::types::Variant responseObj(s);
				responseObj.setEncoding( requestObj.getEncoding() );
				response.setContentObject( responseObj );
			}
			else
			{
				// Received something other than a string.
				// Server echos received object as a utf8 string.
				qpid::types::Variant responseObj( requestObj.asString() );
				responseObj.setEncoding( "utf8" );
				response.setContentObject( requestObj );
			}
			sender.send(response);
			std::cout	<< request.getCorrelationId() << std::endl;
			std::cout	<< "Processed request: "
					<< request.getContentObject()
					<< " -> "
					<< response.getContentObject() << std::endl;
			session.acknowledge();
			sender.close();

	}
public:
	ServerImpl (	const std::string& init_data,
			const std::string& service_queue)
	:	AbstractEndpoint(init_data)
	,	_session(createSession())
	,	_receiver(_session.createReceiver(service_queue+"; {create: always}"))
	{}

	virtual ~ServerImpl ()
	{}

	virtual void run()
	{
		try
		{
			while (true)
			{
				process(_receiver.fetch());
			}	
		}
		catch(const std::exception& error)
		{
			std::cout << error.what() << std::endl;
		}
	}
};

}
