
PYTHON_ADD_MODULE(ctor ctor.cpp)
FILE(COPY ctor.py DESTINATION .)
ADD_TEST(03-Constructors ctor.py)
