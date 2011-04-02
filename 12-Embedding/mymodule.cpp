#include <string>

class Base {
public:
	Base() : mName("Base") {}
	virtual ~Base {}
	std::str name() const
	{ return mName; }
protected:
	Base(const std::string& name) : mName(name) {}
private:
	std::string mName;
}

#include <boost/phyton.hpp>

BOOST_YPTHON_MODULE(mymodule)
{
	class_<Base>("Base")
		.def("__str__", &Base::name)
	;
}

