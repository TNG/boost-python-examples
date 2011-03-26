cmake_minimum_required(VERSION 2.8.3)
FIND_PACKAGE(PythonLibs)

INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
LINK_LIBRARIES(boost_python)

PYTHON_ADD_MODULE(classes classes.cpp)
FILE(COPY classes.py DESTINATION .)
