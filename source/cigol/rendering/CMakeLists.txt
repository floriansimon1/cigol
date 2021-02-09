include(../../../cmake/locations.cmake)

find_package(glm      MODULE REQUIRED)
find_package(glad     MODULE REQUIRED)
find_package(sfml     MODULE REQUIRED)
find_package(range-v3 MODULE REQUIRED)

define_global_output_directory()

add_library(rendering OBJECT
    mesh.hpp
    mesh.cpp

    managed-opengl-resource.cpp
    managed-opengl-resource.hpp

    unit-square.hpp

    shader-binding.cpp
    shader-binding.hpp

    shaders/cigol-shader.cpp
    shaders/cigol-shader.hpp
)

target_link_libraries(rendering
    PRIVATE
        cigol::ecs
        cigol::math
        cigol::data
    
    PUBLIC
        glm::glm
        glad::glad
        range-v3::range-v3
)

add_library(cigol::rendering ALIAS rendering)

install(DIRECTORY shaders/glsl DESTINATION "${OUTPUT_ROOT_DIRECTORY}/shaders")
