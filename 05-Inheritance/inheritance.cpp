#include <iostream>
#include <string>

class Base 
{
public:
	virtual std::string name() const
	{ return "Base"; }
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	virtual std::string name() const
	{ return "Derived"; }
};

void fb(Base *b)
{
	std::cout << b->name() << " called." << std::endl;
}

void fd(Derived *d)
{
	std::cout << "Derived " << d->name() << " called." << std::endl;
}

Base* factory()
{
	return new Derived;
}

#include <boost/python.hpp>
using namespace boost::python;

struct BaseWrap : Base, wrapper<Base>
{
	virtual std::string name() const
	{
		if (override n = this->get_override("name"))
			return n();
		return Base::name();
	}
	std::string default_name() const
	{
		return this->Base::name();
	}
};

BOOST_PYTHON_MODULE(inheritance)
{
	class_<BaseWrap, boost::noncopyable>("Base")
		.def("name", &Base::name, &BaseWrap::default_name)
	;

	class_<Derived, bases<Base> >("Derived")
	;

	def("fb", fb);
	def("fd", fd);
	def("factory", factory, return_value_policy<manage_new_object>());
}	
