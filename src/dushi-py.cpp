#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <Python.h>

#include <dushi.h>

static PyObject* load(PyObject *self, PyObject *args) {
    const char* path;
    if (!PyArg_ParseTuple(args, "|s", &path));

    if(dushi_load((string)path)) return Py_True;
    else return Py_False;
}

static PyObject* reload(PyObject *self, PyObject *args) {
    const char* path;
    if (!PyArg_ParseTuple(args, "|s", &path));

    if(dushi_reload((string)path)) return Py_True;
    else return Py_False;
}

static PyObject* bezem(PyObject *self, PyObject *args, PyObject *kwargs) {
    const char* inpstr;
    int smileys = 0;
    int aids = 0;

    static char *kwlist[] = {"", "smileys", "aids", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|$ii", kwlist, &inpstr, &smileys, &aids)) {
        return NULL;
    }

    string translated = dushi_bezem((string) inpstr, smileys, aids);
    if(!translated.empty()) {
        char *cstr = &translated[0u];
        return Py_BuildValue("s", cstr);
    }
    else
        return Py_BuildValue("");
}

static PyMethodDef dushi_methods[] = {
        {"bezem", (PyCFunction)bezem, METH_VARARGS|METH_KEYWORDS, "ewa nifa"},
        {"load", load, METH_VARARGS, "init jwz"},
        {"reload", reload, METH_VARARGS, "refresh databees"},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef dushi_definition = {PyModuleDef_HEAD_INIT, "dushi", "Wholla", -1, dushi_methods};

PyMODINIT_FUNC PyInit_dushi(void) {
    Py_Initialize();
    return PyModule_Create(&dushi_definition);
}
