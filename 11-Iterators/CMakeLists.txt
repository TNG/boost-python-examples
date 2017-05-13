
PYTHON_ADD_MODULE(iterators iterators.cpp)
FILE(COPY iterators.py DESTINATION .)
ADD_TEST(NAME 11-Iterators COMMAND ${PYTHON_EXECUTABLE} iterators.py)

