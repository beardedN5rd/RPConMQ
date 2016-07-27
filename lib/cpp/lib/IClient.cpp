#include <RPConMQ/Client.hpp>
#include "ClientImpl.hpp"

namespace RPConMQ {

IClient::IClient ()
{}

IClient::~IClient ()
{}

Client IClient::create(	const std::string& init_data,
						const std::string& service_queue)
{
	return Client(new ClientImpl(init_data, service_queue));
}

}
