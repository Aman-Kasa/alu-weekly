#include <Python.h>

// Addition function
static PyObject* add(PyObject* self, PyObject* args) {
    int a, b;
    // Parse two integers from the Python input tuple
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL; // Return NULL if parsing fails
    }
    return PyLong_FromLong(a + b);
}





// Subtraction function
static PyObject* subtract(PyObject* self, PyObject* args) {
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    return PyLong_FromLong(a - b);
}




// Multiplication function
static PyObject* multiply(PyObject* self, PyObject* args) {
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    return PyLong_FromLong(a * b);
}

// Division function
static PyObject* divide(PyObject* self, PyObject* args) {
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    if (b == 0) {
        PyErr_SetString(PyExc_ZeroDivisionError, "Cannot divide by zero.");
        return NULL;
    }
    return PyLong_FromLong(a / b);
}




// Method definitions for the module


static PyMethodDef CalculatorMethods[] = {
    {"add", add, METH_VARARGS, "Add two numbers."},
    {"subtract", subtract, METH_VARARGS, "Subtract two numbers."},
    {"multiply", multiply, METH_VARARGS, "Multiply two numbers."},
    {"divide", divide, METH_VARARGS, "Divide two numbers."},
    {NULL, NULL, 0, NULL}
};


// Module definition
static struct PyModuleDef calculatormodule = {
    PyModuleDef_HEAD_INIT,
    "calculator",
    NULL,
    -1,
    CalculatorMethods
};


// Module initialization
PyMODINIT_FUNC PyInit_calculator(void) {
    return PyModule_Create(&calculatormodule);
}
