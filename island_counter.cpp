#include <tuple>
#include <stdexcept>
#include <cstdlib>
#include <boost/python.hpp>
#include "island_counter.h"

using namespace std;
namespace bpy = boost::python;
void IslandCounter::add_position(int pos)
{
    positions.push_back(pos);
}

bpy::tuple IslandCounter::maximum_stretch(int island_length)
{
    if (positions.size() == 0)
       throw runtime_error("The position vector is empty!");

    
    size_t size_biggest_island = 1;
    size_t size_current_island = 1;
    size_t index_first_elem_biggest_island = 0;
    size_t index_last_elem_biggest_island = 0;;

    size_t index_first_elem_current_island = 0;
    size_t index_last_elem_current_island = 0;

    for (size_t i = 1; i < positions.size(); ++i)
    {
        if (abs(positions[i - 1] - positions[i]) <= island_length)
        {
           ++size_current_island;
           index_last_elem_current_island = i;
        }

        else
        {
            if (size_current_island > size_biggest_island)
            {
                index_first_elem_biggest_island = index_first_elem_current_island;
                index_last_elem_biggest_island = index_last_elem_current_island;
                size_biggest_island = size_current_island;
            }

            index_first_elem_current_island = i;
            size_current_island = 1;
        }
    }

    //handle the case 
    
    if (size_current_island > size_biggest_island)
    {
        size_biggest_island = size_current_island;
        index_last_elem_biggest_island = positions.size() - 1;
    }

    return bpy::make_tuple(positions[index_first_elem_biggest_island], positions[index_last_elem_biggest_island]);
}

void IslandCounter::read(bpy::object reader)
{
    for (bpy::stl_input_iterator<bpy::object> it = reader; 
            it != bpy::stl_input_iterator<bpy::object> (); ++it)
    {
        int pos = bpy::extract<int>(it->attr("POS"));
        positions.push_back(pos);
    }
}

