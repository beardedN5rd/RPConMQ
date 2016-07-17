#pragma once
#include "AbstractEndpoint.hpp"

namespace RPConMQ {

class ReadEndpoint
{
private:
	ExchangeType	_exchange;
	QueueType		_queue;

	static int onCancel(AMQPMessage * message )
	{
		return 0;
	}

	int  onMessage( AMQPMessage * message  )
	{
		uint32_t j = 0;
		char * data = message->getMessage(&j);
		if (data)
			  std::cout << data << std::endl;
		return 0;
	}
public:
	ReadEndpoint (	AbstractEndpoint& 	abstract,
					const std::string& 	queue_name)
	:	_exchange(abstract.createExchange())
	,	_queue(abstract.createQueue(queue_name))
	{
		using namespace std::placeholders;

		_queue->Bind(EXCHANGE_NAME, "");

		_queue->setConsumerTag("tag_123");
		std::function<int(AMQPMessage *)> oM = std::bind(&ReadEndpoint::onMessage,this,_1);
		_queue->addEvent(AMQP_MESSAGE, oM);
		_queue->addEvent(AMQP_CANCEL, ReadEndpoint::onCancel);

		_queue->Consume(AMQP_NOACK);//
	}

	~ReadEndpoint ()
	{}

};

}
