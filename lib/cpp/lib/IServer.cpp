#include <RPConMQ/Server.hpp>
#include "ServerImpl.hpp"

namespace RPConMQ {

IServer::~IServer()
{}

Server IServer::create()
{
	return Server(new ServerImpl());
}

}
