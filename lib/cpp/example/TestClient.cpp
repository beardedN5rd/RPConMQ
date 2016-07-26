#include <qpid/messaging/Address.h>
#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>

#include <cstdlib>
#include <iostream>

#include <sstream>

using namespace qpid::messaging;

using std::stringstream;
using std::string;

int main(int argc, char** argv) {
    const char* url = argc>1 ? argv[1] : "amqp:tcp:127.0.0.1:5672";
    std::string connectionOptions = argc > 2 ? argv[2] : "";

    Connection connection(url, connectionOptions);
     try {
        connection.open();
        Session session = connection.createSession();

        Sender sender = session.createSender("service_queue");

        //create temp queue & receiver...
        Receiver receiver = session.createReceiver("#");
        Address responseQueue = receiver.getAddress();

	// Now send some messages ...
	string s[] = {
            "Twas brillig, and the slithy toves",
            "Did gire and gymble in the wabe.",
            "All mimsy were the borogroves,",
            "And the mome raths outgrabe."
        };

    	Message request;
        request.setReplyTo(responseQueue);
        request.setCorrelationId("foo");
	for (int i=0; i<4; i++) {
            request.setContentObject(s[i]);
            sender.send(request);
            Message response = receiver.fetch();
            std::cout << request.getContentObject() << " -> " << response.getContentObject() << std::endl;
            session.acknowledge(response);
	}
        connection.close();
        return 0;
    } catch(const std::exception& error) {
        std::cout << error.what() << std::endl;
        connection.close();
    }
    return 1;
}

/*
#include <RPConMQ/Client.hpp>

using namespace RPConMQ;

int main ()
{
	 auto client = IClient::create ("");
	 client->request("Snafu");
	 return EXIT_SUCCESS;
}
*/
