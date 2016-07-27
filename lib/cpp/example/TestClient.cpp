#include <RPConMQ/Client.hpp>

using namespace RPConMQ;

int main ()
{
	auto client = IClient::create ("amqp:tcp:127.0.0.1:5672", "foo");
	std::string s[] = {
	            "Twas brillig, and the slithy toves",
	            "Did gire and gymble in the wabe.",
	            "All mimsy were the borogroves,",
	            "And the mome raths outgrabe."
	};

	for (int i=0; i<4; i++)
	{
		client->request(s[i]);
	}

	return EXIT_SUCCESS;
}
