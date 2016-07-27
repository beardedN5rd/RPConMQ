#include <RPConMQ/Server.hpp>
#include "ServerImpl.hpp"

namespace RPConMQ {

IServer::~IServer()
{}

Server IServer::create
(	const std::string& init_data,
	const std::string& service_queue
)
{
	return Server(new ServerImpl(init_data,service_queue));
}

}
