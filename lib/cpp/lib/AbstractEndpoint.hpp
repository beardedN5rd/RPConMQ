#pragma once
#include "internal.hpp"


namespace RPConMQ {

class AbstractEndpoint
{
private:
	qpid::messaging::Connection _connection;

public:
	AbstractEndpoint (const std::string& init_data)
	:	_connection(init_data)
	{
		_connection.open();
	}

	virtual ~AbstractEndpoint ()
	{
		_connection.close();
	}
};

}
