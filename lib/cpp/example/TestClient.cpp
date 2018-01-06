#include <RPConMQ/Client.hpp>

using namespace RPConMQ;

std::string foo()
{
	return "foo";
}

int main ()
{
	auto client =
			IClient::create (	"amqp:tcp:127.0.0.1:5672",
								"foo",
								std::bind(&foo));
	std::string s[] = {
	            "Twas brillig, and the slithy toves",
	            "Did gire and gymble in the wabe.",
	            "All mimsy were the borogroves,",
	            "And the mome raths outgrabe."
	};

	for (int i=0; i<4; i++)
	{
		std::cout	<< s[i]
				<< " -> "
				<< client->request(s[i])
				<< std::endl;
	}

	return EXIT_SUCCESS;
}
