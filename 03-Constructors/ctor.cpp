#include <string>
#include <sstream>

struct Ctor
{
    Ctor(std::string msg) : mMsg(msg) {}
    Ctor(double x,double y)
        {
            std::stringstream os;
            os << x << ":" << y << std::ends;
            set(os.str());
    }
    void set(std::string msg) { mMsg = msg; }
    std::string greet() { return mMsg; }
    std::string mMsg;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(ctor)
{
    class_<Ctor>("Ctor", init<std::string>())
        .def(init<double, double>())
        .def("greet", &Ctor::greet)
        .def("set", &Ctor::set)
    ;

}


