
PYTHON_ADD_MODULE(policies policies.cpp)
FILE(COPY policies.py DESTINATION .)
ADD_TEST(NAME 08-CallPolicies COMMAND ${PYTHON_EXECUTABLE} policies.py)

