cmake_minimum_required(VERSION 3.4)

find_package(Boost)

if (Boost_FOUND)
    include_directories("${Boost_INCLUDE_DIRS}" "/usr/include/python2.7")
    find_package(Boost COMPONENTS python)

    add_library(island_counter_ext SHARED island_counter_ext.cpp island_counter.cpp)
    target_link_libraries(island_counter_ext ${Boost_LIBRARIES})
    set_target_properties(island_counter_ext PROPERTIES PREFIX "")
endif ()
