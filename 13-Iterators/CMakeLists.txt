
PYTHON_ADD_MODULE(iterators iterators.cpp)
FILE(COPY iterators.py DESTINATION .)
ADD_TEST(13-Iterators iterators.py)

