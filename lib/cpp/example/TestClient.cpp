#include <RPConMQ/Client.hpp>

using namespace RPConMQ;

int main ()
{
	 auto client = IClient::create ("foo");
	 client->request("Snafu");
	 return EXIT_SUCCESS;
}
