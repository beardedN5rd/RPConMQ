#include <boost/python.hpp>
#include <RPConMQ/Client.hpp>

using namespace boost::python;
using namespace RPConMQ;

struct IClientWrap : IClient, wrapper<IClient>
{
    Response request(const Request& request)
    {
        return this->get_override("request")(request);
    }
};

BOOST_PYTHON_MODULE(RPConMqClient)
{
    class_<IClientWrap, boost::noncopyable>("IClient")
        .def("request", pure_virtual(&IClient::request))
        .def("create", &IClient::create)
    ;
}

