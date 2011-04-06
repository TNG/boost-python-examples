
PYTHON_ADD_MODULE(myexceptions myexceptions.cpp)
FILE(COPY myexceptions.py DESTINATION .)
ADD_TEST(14-Exceptions myexceptions.py)

