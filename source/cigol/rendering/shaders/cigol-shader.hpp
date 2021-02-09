#pragma once

#include <cigol/rendering/shader-binding.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <memory>

namespace sf {
    class Shader;
}

namespace cigol::rendering {
    std::unique_ptr<sf::Shader>
    getStandardTexturedSurfaceShader();

    void
    unsetTextureForStandardTexturedShader(
        ShaderBinding       binding
    );

    void
    setTextureForStandardTexturedShader(
        ShaderBinding       binding,
        const sf::Texture&  texture,
        const float         textureXScale,
        const float         textureYScale
    );
}
