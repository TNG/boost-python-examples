#include <iostream>
#include <boost/python.hpp>
#include <frameobject.h>
#include "mymodule.hpp"

using namespace boost::python;

dict main_namespace;

void initializeInterpreter()
{
	Py_Initialize();

	object main_module;
	object builtins_module;
	if (PyImport_AppendInittab( (char*)"mymodule", initmymodule) < 0) 
		throw_error_already_set() ;

	main_module = object( borrowed( PyImport_AddModule("__main__") ) );
	handle<> mymodule( PyImport_ImportModule("mymodule") );
	if (!mymodule) {
		if (PyErr_Occurred()) PyErr_PrintEx(0);
		throw_error_already_set() ;
	}

	main_namespace=dict(borrowed( PyModule_GetDict( main_module.ptr() ) ) );
	// do not load other modules in the same way, or more exactly:
	// never store references to imported modules in global variables.
	// the main module is the only module stable enough to survive that.
}

object getFunction(object python_namespace, std::string fname)
{
        handle<> h_function(borrowed(allow_null(
                                         PyDict_GetItemString(python_namespace.ptr(),(char*)fname.c_str())))    );

        if (!h_function) {
                if (PyErr_Occurred()) PyErr_Print();
		throw_error_already_set() ;
        }

        if ( !PyCallable_Check( h_function.get() ) ) {
		throw_error_already_set() ;
        }

        object o_function( h_function );
        return o_function;
}

void executePythonScript(const std::string& fname)
{
	// These searches cannot be put into some initializer function because one must not make these objects static.
	object builtins_module = object( borrowed(PyImport_AddModule("__builtin__") ) );
	object builtins_namespace=dict(borrowed( PyModule_GetDict( builtins_module.ptr() ) ) );
	object builtins_execfile = getFunction(builtins_namespace,"execfile");

	builtins_execfile(fname.c_str(),main_namespace);
}

int main(int argc, char** argv)
{
	initializeInterpreter();
	try {
		//object base = Base();
		//PyDict_SetItem(main_namespace.ptr(), str("base").ptr(), base.ptr());
		main_namespace["x"] = str("a");
		executePythonScript("embedding.py");
	} catch (error_already_set& e) {
		PyErr_PrintEx(0);
	}
	return 0;
}
