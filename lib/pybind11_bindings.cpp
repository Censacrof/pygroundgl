#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "Display.h"
#include "Mesh.h"


PYBIND11_MODULE(pygroundgl, m) {


    py::class_<Display>(m, "Display")
        .def(py::init<int, int, std::string>())
        .def("update", &Display::update)
        .def("getWidth", &Display::getWidth)
        .def("getHeight", &Display::getHeight)
        .def("getRatio", &Display::getRatio)
        .def("isWindowOpen", &Display::isWindowOpen)
        .def("clear", &Display::clear);
}