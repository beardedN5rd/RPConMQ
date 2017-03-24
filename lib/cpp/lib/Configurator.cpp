#include <RPConMQ/Configurator.hpp>

namespace RPConMQ {

Configurator::Configurator (
	const std::string& host,
	const uint16_t port)
:	_host(host)
,	_port(port)
{}

Configurator::~Configurator ()
{}

}
