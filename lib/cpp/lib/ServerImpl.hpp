#pragma once
#include <RPConMQ/Server.hpp>
#include "AbstractEndpoint.hpp"

namespace RPConMQ {

class ServerImpl
:	public virtual IServer
{
public:
	ServerImpl (const std::string& init_data)
	{}

	virtual ~ServerImpl ()
	{}
};

}
