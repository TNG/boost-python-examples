#include <sstream>
#include <string>

class Example {
public:
    Example()
    {}

    void doit() { mS = "void"; }
    std::string doit(unsigned int i)
    {
        std::stringstream s;
        s << i;
        mS = s.str();
        return mS;
    }
    void doit(std::string s) { mS = s; }

    int makeIt(std::string s, int n=1, std::string t="")
    {
        std::stringstream u;
        for (unsigned int i=0; i<n; ++i)
            u << s;
        mS = u.str() + t;
        return n + ( t.size() > 0 ? 1 : 0 );
    }

    std::string print() const { return mS; }
private:
    std::string mS;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(makeIt_overloads, makeIt, 1, 3)

BOOST_PYTHON_MODULE(overload)
{
    void        (Example::*d1)()             = &Example::doit;
    std::string (Example::*d2)(unsigned int) = &Example::doit;
    void        (Example::*d3)(std::string)  = &Example::doit;

    class_<Example>("Example")
        .def("__str__", &Example::print)
        .def("doit", d1)
        .def("doit", d2)
        .def("doit", d3)
        .def("makeIt", &Example::makeIt, makeIt_overloads())
    ;
}	
