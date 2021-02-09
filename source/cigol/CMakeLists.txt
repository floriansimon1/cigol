add_subdirectory(base)
add_subdirectory(data)
add_subdirectory(math)
add_subdirectory(ecs)

add_subdirectory(rendering)

add_subdirectory(application)

find_package(sfml MODULE REQUIRED)
find_package(glad MODULE REQUIRED)

add_executable(cigol
    main.cpp
)

target_link_libraries(cigol
    PRIVATE
        cigol::ecs
        cigol::data
        cigol::base
        cigol::math
        cigol::rendering
        cigol::application

        sfml::sfml
        glad::glad
)

include(../../cmake/locations.cmake)

define_global_output_directory()

install(TARGETS cigol DESTINATION "${OUTPUT_ROOT_DIRECTORY}")
