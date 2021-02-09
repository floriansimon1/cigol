find_package(sfml     MODULE REQUIRED)
find_package(range-v3 MODULE REQUIRED)

add_library(application OBJECT
    main-scene.hpp
    main-scene.cpp
)

target_link_libraries(application
    PRIVATE
        sfml::sfml

        cigol::ecs
        cigol::rendering
)

add_library(cigol::application ALIAS application)
