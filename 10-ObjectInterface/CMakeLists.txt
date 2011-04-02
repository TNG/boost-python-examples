
PYTHON_ADD_MODULE(obj_ifc obj_ifc.cpp)
FILE(COPY obj_ifc.py DESTINATION .)
ADD_TEST(10-ObjectInterface obj_ifc.py)

