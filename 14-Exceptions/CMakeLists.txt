
PYTHON_ADD_MODULE(exceptions exceptions.cpp)
FILE(COPY exceptions.py DESTINATION .)
ADD_TEST(14-Exceptions exceptions.py)

