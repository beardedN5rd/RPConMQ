#include <RPConMQ/Server.hpp>

using namespace RPConMQ;

int main ()
{
	 auto server = IServer::create ("foo");

	 return EXIT_SUCCESS;
}
