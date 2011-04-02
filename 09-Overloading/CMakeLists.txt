
PYTHON_ADD_MODULE(overload overload.cpp)
FILE(COPY overload.py DESTINATION .)
ADD_TEST(09-Overloading overload.py)

