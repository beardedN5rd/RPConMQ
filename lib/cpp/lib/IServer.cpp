#include <RPConMQ/Server.hpp>
#include "ServerImpl.hpp"

namespace RPConMQ {

IServer::~IServer()
{}

Server IServer::createInstance
(	const Configurator& configuration,
	const std::string& service_queue,
	const CallBack&	service_callback
)
{
	return Server(new ServerImpl(	configuration,
									service_queue,
									service_callback));
}

}
