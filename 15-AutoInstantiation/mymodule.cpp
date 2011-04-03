
#include "mymodule.hpp"

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(mymodule)
{
	class_<Base>("Base", init<std::string>())
		.def("__str__", &Base::name)
	;

}

