#pragma once
#include <RPConMQ/essentials.hpp>

namespace RPConMQ {

class Server
{
public:
	Server() = delete
	virtual ~Server();

	using CallBack = std::function<Message(const Message&)>;
	static std::shared_ptr<Server> create ();
}

}
