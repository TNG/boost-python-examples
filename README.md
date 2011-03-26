
# boost::python examples

These are a few examples on how to use the boost::python library to extend Python with C++ libraries.
Some of the are based on the existing tutorial for boost::python from Joel de Guzman at 
<http://www.boost.org/doc/libs/1_46_1/libs/python/doc/tutorial/doc/html/index.html>
but others are independent.

## Prerequistites

+ CMake (>= 2.8.3)
+ Boost (tested with 1.4.2, but should work with >= 1.3.2)
+ Python (tested with 2.7, but should work with >= 2.4)

## Building

+ Set BOOST_ROOT variable if Boost is installed in a non-standard directory
+ create a build directory, e.g. mkdir build directly in this directory.
+ cd to the build dir
+ cmake ..
+ make

