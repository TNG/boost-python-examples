#include <sstream>
#include <string>

class NumberLike
{
public:
	NumberLike(int n = 0) : _n(n) {}
	NumberLike& operator+= (int i)
		{ _n += i; return *this; }
	std::string toString() const
		{ std::stringstream s; s<<_n; return s.str(); }
private:
	int _n;
};

NumberLike operator+(NumberLike n, int i)
	{ n += i; return n; };


#include <boost/python.hpp>
using namespace boost::python;


BOOST_PYTHON_MODULE(operators)
{
	class_<NumberLike>("NumberLike")
		.def(init<int>())
		.def(self + int())
		.def("__str__", &NumberLike::toString)
	;
}	
