#include <boost/python.hpp>
#include <iostream>
#include <frameobject.h>
#include "mymodule.hpp"

using namespace boost::python;

#if PY_MAJOR_VERSION >= 3
#   define INIT_MODULE PyInit_mymodule
    extern "C" PyObject* INIT_MODULE();
#else
#   define INIT_MODULE initmymodule
    extern "C" void INIT_MODULE();
#endif


int main(int argc, char** argv)
{
    try {
        PyImport_AppendInittab((char*)"mymodule", INIT_MODULE);
        Py_Initialize();
        object main_module = import("__main__");
        dict main_namespace = extract<dict>(main_module.attr("__dict__"));
        object mymodule = import("mymodule");

        main_namespace["precreated_object"] = Base("created on C++ side");
        exec_file("embedding.py", main_namespace, main_namespace);
    } catch (error_already_set& e) {
        PyErr_PrintEx(0);
        return 1;
    }
    return 0;
}
