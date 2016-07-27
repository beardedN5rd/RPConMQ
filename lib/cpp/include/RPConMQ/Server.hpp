#pragma once
#include <RPConMQ/essentials.hpp>

namespace RPConMQ {

class IServer;
using Server = std::shared_ptr<IServer>;

class IServer
{
public:
//	IServer() = delete;
	virtual ~IServer();
	virtual void run() = 0;

	static Server create (	const std::string& init_data,
							const std::string& service_queue,
							const CallBack&	service_callback);
};

}
