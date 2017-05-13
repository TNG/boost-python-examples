
PYTHON_ADD_MODULE(myexceptions myexceptions.cpp)
FILE(COPY myexceptions.py DESTINATION .)
ADD_TEST(NAME 12-Exceptions COMMAND ${PYTHON_EXECUTABLE} myexceptions.py)

