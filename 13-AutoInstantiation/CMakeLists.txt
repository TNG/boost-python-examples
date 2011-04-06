
ADD_EXECUTABLE(auto_instance myextension.cpp auto_instance.cpp)
TARGET_LINK_LIBRARIES(auto_instance ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
FILE(COPY auto_instance.py DESTINATION .)
SET( ENV{PYTHONPATH} . )
ADD_TEST(13-AutoInstantiation auto_instance)

