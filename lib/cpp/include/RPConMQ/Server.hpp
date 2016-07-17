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

	static Server create (const std::string& init_data);
};

}
