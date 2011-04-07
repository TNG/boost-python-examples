
#include <string>

struct World
{
    void set(std::string msg) { mMsg = msg; }
    std::string greet() { return mMsg; }
    std::string mMsg;
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
