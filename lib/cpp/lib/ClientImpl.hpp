#pragma once
#include <RPConMQ/Client.hpp>

namespace RPConMQ {

class ClientImpl :
		public virtual IClient
{
public:
	ClientImpl ()
	{

	}

	virtual ~ClientImpl ()
	{}

	virtual Message request (const Message& message)
	{
		//create correlation id

		//send request to request queue with correlation id and response queue

		//check if result contains correlation id
		return "FooBar";
	}

private:
	std::string create_unique_queue_name()
	{
		return "unique";
	}

};

}
