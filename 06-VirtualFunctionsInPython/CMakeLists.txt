
PYTHON_ADD_MODULE(virtual virtual.cpp)
FILE(COPY virtual.py DESTINATION .)
ADD_TEST(NAME 06-VirtualFunctionsInPython COMMAND ${PYTHON_EXECUTABLE} virtual.py)

