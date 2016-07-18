#pragma once
#include <RPConMQ/Server.hpp>
#include "ReadEndpoint.hpp"
#include "SendEndpoint.hpp"

namespace RPConMQ {

class ServerImpl
:	public virtual IServer
{
private:
	AbstractEndpoint	_endpoint;
	ReadEndpoint		_readEP;
public:
	ServerImpl (const std::string& init_data)
	:	_endpoint(init_data)
	,	_readEP(_endpoint,"foo")
	{}

	virtual ~ServerImpl ()
	{}
};

}
