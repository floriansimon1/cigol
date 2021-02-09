find_package(glm      MODULE REQUIRED)
find_package(sfml     MODULE REQUIRED)
find_package(coro     MODULE REQUIRED)
find_package(range-v3 MODULE REQUIRED)

add_library(ecs OBJECT
    component.hpp
    system.hpp

    scene.cpp
    scene.hpp

    entity.cpp
    entity.hpp
)

target_link_libraries(ecs
    PUBLIC
        glm::glm
        sfml::sfml
        coro::coro
        range-v3::range-v3
)

add_library(cigol::ecs ALIAS ecs)
