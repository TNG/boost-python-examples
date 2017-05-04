
PYTHON_ADD_MODULE(operators operators.cpp)
FILE(COPY operators.py DESTINATION .)
ADD_TEST(NAME 07-Operators COMMAND ${PYTHON_EXECUTABLE} operators.py)

