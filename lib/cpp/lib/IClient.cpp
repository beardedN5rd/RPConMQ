#include <RPConMQ/Client.hpp>
#include "ClientImpl.hpp"

namespace RPConMQ {

IClient::~IClient()
{}

Client IClient::create()
{
	return Client(new ClientImpl());
}

}
