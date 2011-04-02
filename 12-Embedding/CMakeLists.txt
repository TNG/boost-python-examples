
PYTHON_ADD_MODULE(mymodule mymodule.cpp)
ADD_EXECUTABLE(embedding embedding.cpp)
FILE(COPY embedding.py DESTINATION .)
ADD_TEST(12-Embedding embedding)

