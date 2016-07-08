#pragma once
#include <RPConMQ/essentials.hpp>

namespace RPConMQ {

class Client
{
public:
	Client() = delete
	virtual ~Client();
	virtual Message request (const Message& message) = 0;

	static std::shared_ptr<Client> create ();
}

}
