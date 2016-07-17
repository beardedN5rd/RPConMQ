#pragma once
#include "AbstractEndpoint.hpp"

namespace RPConMQ {

class SendEndpoint
{
private:
	ExchangeType		_exchange;
	QueueType			_queue;
public:
	SendEndpoint (	AbstractEndpoint& 	abstract,
					const std::string& 	queue_name)
	:	_exchange(abstract.createExchange())
	,	_queue(abstract.createQueue(queue_name))
	{
		_queue->Bind(EXCHANGE_NAME, "");
	}

	~SendEndpoint ()
	{}

	void publish (const std::string& message)
	{
		_exchange->Publish(message,"");
	}

};

}
