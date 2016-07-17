#pragma once
#include <iostream>
#include <memory>
#include <AMQPcpp.h>

namespace RPConMQ {

using ExchangeType = std::shared_ptr<AMQPExchange>;
using QueueType = std::shared_ptr<AMQPQueue>;

}
