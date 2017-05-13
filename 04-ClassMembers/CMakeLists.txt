
PYTHON_ADD_MODULE(member member.cpp)
FILE(COPY member.py DESTINATION .)
ADD_TEST(NAME 04-ClassMembers COMMAND ${PYTHON_EXECUTABLE} member.py)

