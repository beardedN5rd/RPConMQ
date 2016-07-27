#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <string>

namespace RPConMQ {

	using Response	= std::string;
	using Request	= std::string;
	using CallBack	= std::function<Response(const Request&)>;
	using CorrelationCallBack	= std::function<std::string()>;
}
