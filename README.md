
# boost::python examples

These are a few examples on how to use the boost::python library to extend Python with C++ libraries.
Some of the are based on the [existing tutorial for boost::python from Joel de Guzman](http://www.boost.org/doc/libs/1_46_1/libs/python/doc/tutorial/doc/html/index.html "Boost.Python tutorial").
Others are independent.

## Prerequisites

### general
+ [CMake](http://www.cmake.org "CMake project page") (>= 2.8.3)
+ [Boost](http://www.boost.org/ "Boost project page") (tested with 1.4.2, but should work with >= 1.3.2)
+ [Python](http://www.python.org "Python home page") (tested with 2.7, but should work with >= 2.2)
+ a C++ compiler for your platform, e.g. [GCC](http://gcc.gnu.org "GCC home") or [MinGW](http://www.mingw.org "Minimalist GNU for Windows")

The examples should work on Linux, Windows and Mac, but currently have not bee tested under Windows.

### Mac OS X with [homebrew](http://brew.sh)

There is a special package needed called boost-python. The standard boost package will not be recognized by cmake. 

+ `brew install cmake boost-python`

## Building

+ Set the `BOOST_ROOT` environment variable if Boost is installed in a non-standard directory
+ create a build directory, e.g. directly in the project directory and cd to it: `mkdir build ; cd build`
+ run `cmake ..` and afterwards `make`

Alternatively, run the provided `build.sh` script.

## Tests

All examples contain tests, but these only try to run the examples without checking the output. Their purpose is mainly to make sure that compilation works and produces valid Python modules.
