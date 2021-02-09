find_package(sfml MODULE REQUIRED)

add_library(math OBJECT
    random.hpp
    random.implementation.hpp
)

add_library(cigol::math ALIAS math)

target_link_libraries(math
    PRIVATE
        cigol::base

    PUBLIC
        sfml::sfml
)
