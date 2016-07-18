#include <RPConMQ/Client.hpp>

using namespace RPConMQ;

int main ()
{
	 auto client = IClient::create ("");
	 client->request("Snafu");
	 return EXIT_SUCCESS;
}
