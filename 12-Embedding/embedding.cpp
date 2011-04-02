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
		if (PyErr_Occurred()) PyErr_Print();
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

std::string printTB(PyObject *f)
{
        PyTracebackObject *tb = (PyTracebackObject *)f;
        int err = 0;
        std::ostringstream os;
        //os << "Traceback:\n";
        while (tb != NULL && err == 0)
        {
                os << "  File \x22"<<PyString_AsString(tb->tb_frame->f_code->co_filename)
                   << "\x22, line "<<tb->tb_lineno<<", in "
                   << PyString_AsString(tb->tb_frame->f_code->co_name)
                   << "\n";
                tb = tb->tb_next;
                if (err == 0)
                        err = PyErr_CheckSignals();
        }
        os.flush();
        return os.str();
}


std::string getPythonException()
{
        PyObject* type = 0;
        PyObject* value = 0;
        PyObject* tb = 0;
        PyErr_Fetch(&type,&value,&tb);

        try {
                handle<> type_o( allow_null(type) );
                handle<> value_o(value);
                handle<> tb_o( allow_null(tb) );

                handle<> type_str(PyObject_Str(type_o.get()));
                handle<> value_str(PyObject_Str(value_o.get()));
                handle<> tb_str(PyObject_Str(tb_o.get()));

                std::string ret = "Error in python execution:\n";
                if (tb_str.get()!=0)
                        ret += "Traceback (most recent call last):\n" + printTB(tb_o.get());

                std::string type_string = PyString_AsString(type_str.get());
                if (type_string.find("exceptions.")==0)
                        type_string=type_string.substr(11);
                ret += type_string + ": ";
                ret += PyString_AsString(value_str.get());
                ret += "\n";
                return ret;
        }
        catch (error_already_set&)
        {
                return "Error during python exception elucidation.";
        }
}


int main(int argc, char** argv)
{
	initializeInterpreter();
	try {
		executePythonScript("embedding.py");
	} catch (error_already_set& e) {
		std::cerr << getPythonException() << std::endl;
	}
	return 0;
}
