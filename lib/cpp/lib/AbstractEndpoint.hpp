#pragma once
#include "internal.hpp"

namespace RPConMQ {

static const std::string EXCHANGE_NAME = "exchange";

class AbstractEndpoint
{
public:
	AbstractEndpoint (const std::string& init_data)
	:	_connection(init_data)
	{}

	virtual ~AbstractEndpoint ()
	{}

	ExchangeType createExchange()
	{
		static const std::string EXCHANGE_TYPE = "direct";

		auto ex = _connection.createExchange(EXCHANGE_NAME);
		ex->Declare(EXCHANGE_NAME, EXCHANGE_TYPE);

		ex->setHeader("Delivery-mode", 2);
		ex->setHeader("Content-type", "text/text");
		ex->setHeader("Content-encoding", "UTF-8");
		return ExchangeType(ex);
	}

	QueueType createQueue(const std::string& queue_name)
	{
		auto queue = _connection.createQueue(queue_name);
		queue->Declare();
		return QueueType(queue);
	}
private:
	AMQP _connection;
};

}
