#include <iostream>
#include <string>

class Base 
{
public:
    virtual std::string name() const { return "Base"; }
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    virtual std::string name() const { return "Derived"; }
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

BOOST_PYTHON_MODULE(inheritance)
{
    class_<Base, boost::noncopyable>("Base")
        .def("name", &Base::name)
    ;

    class_<Derived, bases<Base> >("Derived")
    ;

    def("fb", fb);
    def("fd", fd);
    def("factory", factory, return_value_policy<manage_new_object>());
}	
