#include <sstream>
#include <string>

class Example {
    Example(std::string n) : mName(n) {}
    std::string mName;
public:
    std::string name() const { return mName; }
    static Example* factory()
    {
        return new Example("factory");
    }
    static Example* singleton()
    {
        static Example instance = Example("singleton");
        return &instance;
    }
};

#include <boost/python.hpp>
using namespace boost::python;


BOOST_PYTHON_MODULE(policies)
{
    class_<Example>("Example", no_init)
        .def("__str__", &Example::name)
        .def("factory", &Example::factory,
            return_value_policy<manage_new_object>())
        .staticmethod("factory")
        .def("singleton", &Example::singleton,
            return_value_policy<reference_existing_object>())
        .staticmethod("singleton")
    ;
}	
