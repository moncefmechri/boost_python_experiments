#include "island_counter.h"
#include <boost/python.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(island_counter_ext)
{
    class_<IslandCounter>("IslandCounter")
        .def("add_position", &IslandCounter::add_position)
        .def("maximum_stretch", &IslandCounter::maximum_stretch)
        .def("read", &IslandCounter::read)
    ;
}

