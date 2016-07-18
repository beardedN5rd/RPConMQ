#include <iostream>
#include <RPConMQ/Server.hpp>

using namespace RPConMQ;

int main ()
{

	 try
	 {
		 auto server = IServer::create ("");
	 }
	 catch (const std::exception& e)
	 {
		 std::cout << e.what() << std::endl;
	 }
	 return EXIT_SUCCESS;
}
