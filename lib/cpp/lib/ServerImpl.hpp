#pragma once
#include <RPConMQ/Server.hpp>

namespace RPConMQ {

class ServerImpl
:	public virtual IServer
{
public:
	virtual ~ServerImpl()
	{}
};

}
