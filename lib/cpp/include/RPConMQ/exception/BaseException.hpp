#pragma once
#include <stdexcept>

namespace RPConMQ {

class BaseException
:	public std::runtime_error
{
protected:
    const std::string _message;
public:
    explicit BaseException (const std::string& message)
    :	_message(message)
    {}

    virtual ~BaseException () throw ()
	{}

    virtual const char* what() const throw ()
    {
       return _message.c_str();
    }
};

}
