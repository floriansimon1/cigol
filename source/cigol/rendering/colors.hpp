#pragma once

#include <SFML/Graphics/Color.hpp>

#include <vector>

namespace cigol::rendering {
    std::vector<sf::Color>
    getDistinctColorsArray(
        const unsigned numberOfColors
    );
}