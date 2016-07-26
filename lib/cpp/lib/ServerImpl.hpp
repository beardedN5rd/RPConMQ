#pragma once
#include <RPConMQ/Server.hpp>
#include "AbstractEndpoint.hpp"

namespace RPConMQ {

class ServerImpl
:	public virtual IServer
{
private:
	AbstractEndpoint			_abstract;
	qpid::messaging::Receiver	_receiver;
public:
	ServerImpl (const std::string& init_data,
				const std::string& service_queue)
	:	_abstract(init_data)
	,	_receiver(_abstract.session().createReceiver(service_queue+"; {create: always}"))
	{}

	virtual ~ServerImpl ()
	{}

	void run()
	{

	}
};

}
