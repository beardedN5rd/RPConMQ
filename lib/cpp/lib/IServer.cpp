#include <RPConMQ/Server.hpp>
#include "ServerImpl.hpp"

namespace RPConMQ {

IServer::~IServer()
{}

Server IServer::create
(	const std::string& init_data,
	const std::string& service_queue,
	const CallBack&	service_callback
)
{
	return Server(new ServerImpl(	init_data,
									service_queue,
									service_callback));
}

}
