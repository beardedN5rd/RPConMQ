#pragma once
#include "internal.hpp"


namespace RPConMQ {

class AbstractEndpoint
{
private:
	qpid::messaging::Connection _connection;

	static std::string create_init_string(const Configurator& config)
	{
			return std::string("amqp:tcp:")
						+ config.host()
						+ ":"
						+ std::to_string(config.port());
	}
protected:
	qpid::messaging::Session createSession()
	{
		return _connection.createSession();
	}
public:
	AbstractEndpoint (const Configurator& configuration)
	:	_connection(create_init_string(configuration))
	{
		_connection.open();
	}

	virtual ~AbstractEndpoint ()
	{
		_connection.close();
	}
};

}
