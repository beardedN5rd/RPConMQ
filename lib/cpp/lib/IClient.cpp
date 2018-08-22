#include <RPConMQ/Client.hpp>
#include "ClientImpl.hpp"

namespace RPConMQ {

IClient::IClient ()
{}

IClient::~IClient ()
{}

Client IClient::createInstance
(	const Configurator& configuration,
	const std::string& service_queue,
  const CorrelationCallBack& correlation_callback)
{
	return Client(new ClientImpl(configuration, service_queue,correlation_callback));
}

}
