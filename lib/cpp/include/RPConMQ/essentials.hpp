#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <string>

namespace RPConMQ {

	using Message	= std::string;
	using CallBack	= std::function<Message(const Message&)>;
}
