
PYTHON_ADD_MODULE(embedding embedding.cpp)
FILE(COPY embedding.py DESTINATION .)
ADD_TEST(12-Embedding embedding.py)

