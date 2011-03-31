
PYTHON_ADD_MODULE(inheritance inheritance.cpp)
FILE(COPY inheritance.py DESTINATION .)
ADD_TEST(05-Inheritance inheritance.py)

