#pragma once
#include <RPConMQ/Client.hpp>
#include "ReadEndpoint.hpp"
#include "SendEndpoint.hpp"

namespace RPConMQ {

class ClientImpl
:	public virtual IClient
{
private:
	AbstractEndpoint	_endpoint;
	SendEndpoint		_sendEP;
public:
	ClientImpl (const std::string& init_data)
	:	_endpoint(init_data)
	,	_sendEP(_endpoint,"foo")
	{}

	virtual ~ClientImpl ()
	{}

	virtual Message request (const Message& message)
	{
		_sendEP.publish(message);
		//create correlation id

		//send request to request queue with correlation id and response queue

		//check if result contains correlation id
		return "FooBar";
	}

private:
	std::string create_unique_queue_name ()
	{
		return "unique";
	}

};

}
