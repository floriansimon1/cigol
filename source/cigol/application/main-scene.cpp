#include <cigol/application/main-scene.hpp>

#include <cigol/application/generate-base-image.hpp>

#include <SFML/Graphics/Image.hpp>

namespace cigol::application {
    cigol::ecs::Scene
    makeMainScene(
        const unsigned width,
        const unsigned height
    ) {
        cigol::ecs::Scene scene;

        const auto baseState = generateBaseState(width, height);

        sf::Image image;

        image.create(width, height, reinterpret_cast<const uint8_t*>(baseState.data()));

        return scene;
    }
}
