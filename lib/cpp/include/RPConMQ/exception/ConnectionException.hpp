#pragma once
#include <RPConMQ/exception/BaseException.hpp>

namespace RPConMQ {

class ConnectionException
:	public BaseException
{
	using BaseException::BaseException;
};


}
