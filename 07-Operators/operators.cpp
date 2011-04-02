#include <sstream>
#include <string>

class NumberLike
{
public:
	NumberLike(int n = 0) : _n(n) {}
	NumberLike& operator+= (int i)
		{ _n += i; return *this; }
	std::string str() const
		{ std::stringstream s; s << _n; return s.str(); }
    std::string repr() const		
		{ std::stringstream s; s << "NumberLike("<< _n<<")"; return s.str(); }
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
		.def(init< optional<int> >())
		.def(self + int())
		.def("__str__", &NumberLike::str)
		.def("__repr__", &NumberLike::repr)
	;
}	
