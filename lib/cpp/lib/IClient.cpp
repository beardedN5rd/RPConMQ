#include <RPConMQ/Client.hpp>
#include "ClientImpl.hpp"

namespace RPConMQ {

IClient::~IClient()
{}

Client IClient::create(const std::string& init_data)
{
	return Client(new ClientImpl(init_data,"foo"));
}

}
