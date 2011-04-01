
PYTHON_ADD_MODULE(virtual virtual.cpp)
FILE(COPY virtual.py DESTINATION .)
ADD_TEST(06-VirtualFunctionsInPython virtual.py)

