
PYTHON_ADD_MODULE(classes classes.cpp)
FILE(COPY classes.py DESTINATION .)
ADD_TEST(02-ExposingClasses classes.py)
