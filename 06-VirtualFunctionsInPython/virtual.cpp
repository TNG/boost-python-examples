#include <iostream>
#include <string>

class Base 
{
public:
    virtual std::string name() const { return "Base"; }
    virtual ~Base() {}
};

void identify(Base *b)
{
    std::cout << b->name() << " called." << std::endl;
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

BOOST_PYTHON_MODULE(virtual)
{
    class_<BaseWrap, boost::noncopyable>("Base")
        .def("name", &Base::name, &BaseWrap::default_name)
    ;

    def("identify", identify);
}	
