
#include <boost/python.hpp>
#include "myextension.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(myextension)
{
    class_<Base>("Base", init<std::string>())
        .def("__str__", &Base::name)
    ;

}

