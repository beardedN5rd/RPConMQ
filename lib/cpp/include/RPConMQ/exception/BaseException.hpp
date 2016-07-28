#pragma once
#include <stdexcept>

namespace RPConMQ {

class BaseException
:	public std::runtime_error
{
public:
    explicit BaseException (const std::string& message)
    :	runtime_error(message)
    {}

    virtual ~BaseException () throw ()
    {} 
};

}
