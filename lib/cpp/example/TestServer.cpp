#include <RPConMQ/Server.hpp>

using namespace RPConMQ;

int main ()
{

	 try
	 {
		 auto server = IServer::create ("amqp:tcp:127.0.0.1:5672", "foo");
		 server->run();
	 }
	 catch (const std::exception& e)
	 {
		 std::cout << e.what() << std::endl;
	 }
	 return EXIT_SUCCESS;
}
