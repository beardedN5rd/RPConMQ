#include <RPConMQ/Server.hpp>
#include "ServerImpl.hpp"

namespace RPConMQ {

IServer::~IServer()
{}

Server IServer::create(const std::string& init_data)
{
	return Server(new ServerImpl(init_data));
}

}
