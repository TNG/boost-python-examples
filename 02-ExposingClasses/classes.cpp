
#include <string>

struct World
{
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(classes)
{
    class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
};
