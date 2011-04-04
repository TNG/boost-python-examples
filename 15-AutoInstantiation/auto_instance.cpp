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
	try {
		initializeInterpreter();
		exec_file( str("auto_instance.py"), main_namespace, main_namespace);
		object BaseClass = main_namespace["Base"];
		PyTypeObject* base_class = reinterpret_cast<PyTypeObject*>(BaseClass.ptr());
		list keys = main_namespace.keys();
		list items = main_namespace.items();
		unsigned int n = len(items);
		for (unsigned int i = 0; i<n ; ++i) {
			object k = keys[i];
			std::string ks = extract<std::string>(k); 
			std::cout << i << " " << ks ;
			object item = items[i];
			PyObject* item_ptr = item.ptr();
			if ( PyType_Check(item_ptr) != 0 ) {
				std::cout << " Type";
				PyTypeObject* type_obj = reinterpret_cast<PyTypeObject*>(item_ptr);
				if ( ( type_obj != base_class) && ( PyType_IsSubtype( type_obj,  base_class) > 0) ) {
					object obj = items[i]();
					const Base& base_obj = extract<Base>(obj);
					std::cout << base_obj.name() << std::endl;
				}
			}
			std::cout << std::endl;
		}
			
		// collect all classes derived from Base
		// instantiate objects from each class
		// call name on each object	
	} catch (error_already_set& e) {
		PyErr_PrintEx(0);
		return 1;
	}
	return 0;
}
