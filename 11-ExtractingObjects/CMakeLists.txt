
PYTHON_ADD_MODULE(obj_extraction obj_extraction.cpp)
FILE(COPY obj_extraction.py DESTINATION .)
ADD_TEST(11-ExtractingObjects obj_extraction.py)

