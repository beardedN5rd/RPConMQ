#pragma once
#include <RPConMQ/essentials.hpp>

namespace RPConMQ {

class IClient;
using Client = std::shared_ptr<IClient>;

class IClient
{
public:
//	IClient () = delete;
	virtual ~IClient ();
	virtual Message request (const Message& message) = 0;

	static Client create (const std::string& init_data);
};

}
