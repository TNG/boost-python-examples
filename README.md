
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

The examples should work on Linux, Windows and Mac, but currently have not been tested under Windows.

### Mac OS X with [homebrew](http://brew.sh)

There is a special package needed called boost-python. The standard boost package will not be recognized by cmake. 

+ `brew install cmake boost-python`

Furthermore, for the homebrew python lib to be used, its path must be provided to cmake. This is handled in the `build.sh` script, but for reference, or if any issues arise, that can be done manually as follows (substitute the path as appropriate for your Python version):

    cmake -DPYTHON_LIBRARY=/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/lib/libpython2.7.dylib ..

## Building

+ Set the `BOOST_ROOT` environment variable if Boost is installed in a non-standard directory
+ create a build directory, e.g. directly in the project directory and cd to it: `mkdir build ; cd build`
+ run `cmake ..` and afterwards `make`

Alternatively, run the provided `build.sh` script.

## Tests

All examples contain tests, but these only try to run the examples without checking the output. Their purpose is mainly to make sure that compilation works and produces valid Python modules.

## Python 3

The code works with Python 3 both on Linux and on OS X. However, there are several caveats.

### Linux

+ Build Boost::Python against Python 3 (needs at least version 1.56.0)
+ make sure `python` resolves to python3 (e.g., by using a python3 VE)
+ run `cmake -DBOOST_ROOT=xxx ..`

### OS X (again with homebrew)

Some effort has been made to make Python 3 compilation automatic, by making modifications to `build.sh` and `CMakeLists.txt` that account for quirks on the Apple platform regarding cmake, paths, and naming conventions for python/python3. Having said that, if you use `build.sh`, then you will still need to do the following:

+ Build Boost::Python against Python 3 (needs at least version 1.56.0)
+ make sure `python` resolves to python3 (e.g., by using virtualenv)

If you are building without `build.sh`, then you will additionally need to:

+ run `cmake -DBOOST_ROOT=xxx -DPYTHON_LIBRARY=xxx -DPYTHON_INCLUDE_DIR=xxx ..`
+ As of the time of this writing, the naming convention is that python2 is called "python" and python3 is called "python3" on the Apple platform. Therefore, in `CMakeLists.txt` verify that the line `FIND_PACKAGE(Boost COMPONENTS python)` is changed to `FIND_PACKAGE(Boost COMPONENTS python3)`.
