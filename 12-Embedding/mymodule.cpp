#include <string>

class Base {
public:
	Base() : mName("Base") {}
	virtual ~Base() {}
	std::string name() const
	{ return mName; }
protected:
	Base(const std::string& name) : mName(name) {}
private:
	std::string mName;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(mymodule)
{
	class_<Base>("Base")
		.def("__str__", &Base::name)
	;
}

