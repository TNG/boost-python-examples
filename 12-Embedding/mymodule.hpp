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

extern "C" void initmymodule();
