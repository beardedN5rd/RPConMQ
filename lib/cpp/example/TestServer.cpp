#include <algorithm>
#include <RPConMQ/Server.hpp>

using namespace RPConMQ;

Response foo(const Request& request)
{
	Response response = request;
	std::transform(	response.begin(), response.end(),
					response.begin(),
					toupper);
	return response;
}

int main ()
{
	 try
	 {
		 auto server =
				 IServer::createInstance (Configurator(),
						 	 	 									"foo",
						 	 	 									std::bind(&foo, std::placeholders::_1));
		 server->run();
	 }
	 catch (const std::exception& e)
	 {
		 std::cout << e.what() << std::endl;
	 }
	 return EXIT_SUCCESS;
}
