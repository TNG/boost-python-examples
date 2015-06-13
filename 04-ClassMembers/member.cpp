#include <string>
#include <sstream>

class SomeClass
{
public:
    SomeClass(std::string n) : name(n), mNumber(0.0) {}

    std::string name;

    double getNumber() const { return mNumber; }
    void setNumber(double n)
    {
        if (n>3.141592654)
            n = -1;
        mNumber = n;
    }

private:
    double mNumber;
};


#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(member)
{
    class_<SomeClass>("SomeClass", init<std::string>())
        .def_readwrite("name", & SomeClass::name)
        .add_property("number", &SomeClass::getNumber, &SomeClass::setNumber)
    ;

}


