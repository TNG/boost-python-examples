#include <string>

class Base {
public:
    Base() : mName("Base") {}
    Base(const std::string& name) : mName(name) {}
    virtual ~Base() {}
    std::string name() const
    { return mName; }
private:
    std::string mName;
};

