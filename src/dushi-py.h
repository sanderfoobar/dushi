#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

#define Py_False ((PyObject *) &_Py_FalseStruct)
#define Py_True ((PyObject *) &_Py_TrueStruct)

static PyObject* load(PyObject *self, PyObject *args);
static PyObject* reload(PyObject *self, PyObject *args);
static PyObject* bezem(PyObject *self, PyObject *args, PyObject *kwargs);
static PyMethodDef dushi_methods[];
static struct PyModuleDef dushi_definition;
PyMODINIT_FUNC PyInit_dushi(void);
