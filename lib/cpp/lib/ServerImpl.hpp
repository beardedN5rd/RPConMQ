#pragma once
#include <RPConMQ/Server.hpp>
#include "AbstractEndpoint.hpp"

namespace RPConMQ {

class ServerImpl
:	public virtual IServer
,	public AbstractEndpoint
{
private:
	CallBack					_callback;
	qpid::messaging::Session	_session;
	qpid::messaging::Sender		_sender;
	qpid::messaging::Receiver	_receiver;

	void process(const qpid::messaging::Message& request)
	{
		const qpid::messaging::Address& address = request.getReplyTo();
		if (address)
			respond(request, address);
		else
		{
			std::cerr	<< "Error: no reply address specified for request: "
					<< request.getContent()
					<< std::endl;
			_session.reject(const_cast<qpid::messaging::Message&>(request));
		}
	}

	void respond(	const qpid::messaging::Message& request,
					const qpid::messaging::Address& address)
	{
		qpid::messaging::Sender sender = _session.createSender(address);
		qpid::messaging::Message response;

		qpid::types::Variant requestObj = request.getContentObject();
		if (requestObj.getType() == qpid::types::VAR_STRING)
		{
			std::string s = _callback(requestObj);
			qpid::types::Variant responseObj(s);
			responseObj.setEncoding( requestObj.getEncoding() );
			response.setCorrelationId(request.getCorrelationId());
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
		std::cout	<< "Processed request: "
					<< request.getContentObject()
					<< " -> "
					<< response.getContentObject()
					<< std::endl;
		_session.acknowledge();
		sender.close();
	}
public:
	ServerImpl (	const Configurator& configuration,
								const std::string& service_queue,
								const CallBack&	service_callback)
	:	AbstractEndpoint(configuration)
	,	_callback(service_callback)
	,	_session(createSession())
	,	_receiver(_session.createReceiver(service_queue+"; {create: always}"))
	{}

	virtual ~ServerImpl ()
	{}

	virtual void run()
	{
		while (true)
		{
			try
			{
				process(_receiver.fetch());
			}
			catch(const std::exception& error)
			{
				std::cout << error.what() << std::endl;
			}
		}
	}
};

}
