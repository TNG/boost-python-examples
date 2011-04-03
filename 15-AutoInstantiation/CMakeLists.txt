
ADD_EXECUTABLE(auto_instance mymodule.cpp auto_instance.cpp)
TARGET_LINK_LIBRARIES(auto_instance ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
FILE(COPY auto_instance.py DESTINATION .)
ADD_TEST(15-AutoInstantiation auto_instance)

