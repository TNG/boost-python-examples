
PYTHON_ADD_MODULE(operators operators.cpp)
FILE(COPY operators.py DESTINATION .)
ADD_TEST(07-Operators operators.py)

