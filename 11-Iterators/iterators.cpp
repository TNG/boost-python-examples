#include <sstream>
#include <string>
#include <vector>

class Example {
public:
    Example() {}
    void add(const std::string& s)
    {
        mS.push_back(s);
    }

    std::vector<std::string>::iterator begin()
    {
        return mS.begin();
    }
    std::vector<std::string>::iterator end()
    {
        return mS.end();
    }

private:
    std::vector<std::string> mS;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(iterators)
{
    class_<Example>("Example")
        .def("strings", range(&Example::begin, &Example::end))
        .def("add", &Example::add)
    ;
}	
