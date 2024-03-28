// Author: DotykProboszcza

#include <pybind11/pybind11.h>

int add(int a, int b) {
    return a + b;
}

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.def("add", &add);
}