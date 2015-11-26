#ifndef ISLAND_COUNTER_H
#define ISLAND_COUNTER_H

#include <vector>
#include <boost/python.hpp>

struct IslandCounter
{
    std::vector<int> positions;
public:
    void add_position(int pos);
    boost::python::tuple maximum_stretch(int island_length);
    void read(boost::python::object reader);
};

#endif
