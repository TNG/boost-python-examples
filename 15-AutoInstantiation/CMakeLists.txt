
PYTHON_ADD_MODULE(auto_instance auto_instance.cpp)
FILE(COPY auto_instance.py DESTINATION .)
ADD_TEST(15-AutoInstantiation auto_instance.py)

