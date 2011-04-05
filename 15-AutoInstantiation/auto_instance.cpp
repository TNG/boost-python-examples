#include <iostream>
#include <boost/python.hpp>
#include "myextension.hpp"

using namespace boost::python;

int main(int argc, char** argv)
{
	try {
		Py_Initialize();
		object main_module = import("__main__");
		dict main_namespace = extract<dict>(main_module.attr("__dict__"));
		object myextension = import("myextension");
		dict myextension_namespace = extract<dict>(myextension.attr("__dict__"));

		exec_file( str("auto_instance.py"), main_namespace, main_namespace);
		object BaseClass = myextension_namespace["Base"];
		PyTypeObject* base_class = reinterpret_cast<PyTypeObject*>(BaseClass.ptr());
		list keys = main_namespace.keys();
		list items = main_namespace.items();
		for (unsigned int i = 0; i<len(items) ; ++i) {
			object k = keys[i];
			object item = main_namespace[k];
			PyObject* item_ptr = item.ptr();
			if ( PyType_Check(item_ptr) != 0 ) {
				PyTypeObject* type_obj = reinterpret_cast<PyTypeObject*>(item_ptr);
				if ( ( type_obj != base_class) && ( PyType_IsSubtype( type_obj,  base_class) > 0) ) {
					object obj = item();
					const Base& base_obj = extract<Base>(obj);
					std::cout << base_obj.name() << std::endl;
				}
			}
		}
			
	} catch (error_already_set& e) {
		PyErr_PrintEx(0);
		return 1;
	}
	return 0;
}
