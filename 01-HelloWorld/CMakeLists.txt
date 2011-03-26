cmake_minimum_required(VERSION 2.8.3)
FIND_PACKAGE(PythonLibs)

INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
LINK_LIBRARIES(boost_python)

PYTHON_ADD_MODULE(hello hello.cpp)
file(COPY hello.py DESTINATION .)
