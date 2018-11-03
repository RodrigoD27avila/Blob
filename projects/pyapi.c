#include "Python.h"

int main(int argc, char **argv)
{
    Py_Initialize();

    struct PyTuple *obj;
    obj = PyTuple_New(3);

    PyTuple_SetItem(obj, 0, PyInt_FromLong(1L));
    PyTuple_SetItem(obj, 1, PyInt_FromLong(2L));
    PyTuple_SetItem(obj, 2, PyString_FromString("three"));

    Py_Finalize();
    return 0;
}
