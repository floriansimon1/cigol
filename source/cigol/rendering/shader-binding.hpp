#pragma once

#include <cigol/base/non-copyable.hpp>

#include <SFML/Graphics/Shader.hpp>

namespace cigol::rendering {
    // Note that this class offers no guarantee that nobody will bind another shader while this one is supposed to be bound.
    class ShaderBinding: private cigol::base::NonCopyable {
        private:
            bool moved = false;

        public:
            ShaderBinding(
                sf::Shader& shader
            );

            ShaderBinding(
                ShaderBinding&& shader
            );

            ~ShaderBinding();

            sf::Shader& shader;
    };
}
