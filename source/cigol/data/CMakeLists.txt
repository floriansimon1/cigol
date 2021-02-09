
find_package(sfml MODULE REQUIRED)

add_library(data OBJECT
    paths.cpp
    paths.hpp
)

target_link_libraries(data
    PUBLIC
        sfml::sfml
)

include(../../../cmake/locations.cmake)

define_global_output_directory()

target_set_runtime_shader_location_define(data)

add_library(cigol::data ALIAS data)
