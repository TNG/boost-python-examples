
PYTHON_ADD_MODULE(overload overload.cpp)
FILE(COPY overload.py DESTINATION .)
ADD_TEST(NAME 09-Overloading COMMAND ${PYTHON_EXECUTABLE} overload.py)

