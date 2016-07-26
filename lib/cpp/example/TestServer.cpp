#include <qpid/messaging/Address.h>
#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>
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
        Receiver receiver = session.createReceiver("service_queue; {create: always}");

        while (true) {
            Message request = receiver.fetch();
            const Address& address = request.getReplyTo();
            std::cout << request.getCorrelationId() << std::endl;
            if (address) {
                Sender sender = session.createSender(address);
                Message response;

                qpid::types::Variant requestObj = request.getContentObject();
                if (requestObj.getType() == qpid::types::VAR_STRING) {
                    // Received a string.
                    // Server returns request string in upper case with same encoding.
                    std::string s = requestObj;
                    std::transform(s.begin(), s.end(), s.begin(), toupper);
                    qpid::types::Variant responseObj(s);
                    responseObj.setEncoding( requestObj.getEncoding() );
                    response.setContentObject( responseObj );
                } else {
                    // Received something other than a string.
                    // Server echos received object as a utf8 string.
                    qpid::types::Variant responseObj( requestObj.asString() );
                    responseObj.setEncoding( "utf8" );
                    response.setContentObject( requestObj );
                }
                sender.send(response);
                std::cout << "Processed request: "
                          << request.getContentObject()
                          << " -> "
                          << response.getContentObject() << std::endl;
                session.acknowledge();
                sender.close();
            } else {
                std::cerr << "Error: no reply address specified for request: " << request.getContent() << std::endl;
                session.reject(request);
            }
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
*/
