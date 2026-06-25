#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <string.h>

// Function to read /proc/meminfo and return used RAM in Megabytes
static PyObject* get_ram_usage(PyObject* self, PyObject* args) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        PyErr_SetString(PyExc_RuntimeError, "Cannot open /proc/meminfo. Are you on Linux?");
        return NULL;
    }

    char buffer[256];
    long total_mem = 0;
    long available_mem = 0;

    // Parse the file line by line
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_mem) == 1) continue;
        if (sscanf(buffer, "MemAvailable: %ld kB", &available_mem) == 1) continue;
    }
    fclose(fp);

    // Calculate used memory and convert kilobytes to megabytes
    long used_mem_mb = (total_mem - available_mem) / 1024;

    // Return the value as a Python Long
    return Py_BuildValue("l", used_mem_mb);
}

// Map the Python method name to the C function
static PyMethodDef RamMethods[] = {
    {"get_ram_usage", get_ram_usage, METH_VARARGS, "Get currently used RAM in MB."},
    {NULL, NULL, 0, NULL}
};

// Define the module
static struct PyModuleDef rammodule = {
    PyModuleDef_HEAD_INIT,
    "ram_monitor",
    "A C extension to monitor RAM usage.",
    -1,
    RamMethods
};

// Initialize the module
PyMODINIT_FUNC PyInit_ram_monitor(void) {
    return PyModule_Create(&rammodule);
}
