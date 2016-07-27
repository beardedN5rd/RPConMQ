#pragma once
#include <RPConMQ/essentials.hpp>

namespace RPConMQ {

class IClient;
using Client = std::shared_ptr<IClient>;

class IClient
{
protected:
	IClient ();
public:
	virtual ~IClient ();
	virtual Response request (const Request& request) = 0;

	static Client create (	const std::string& init_data,
							const std::string& service_queue);
};

}
