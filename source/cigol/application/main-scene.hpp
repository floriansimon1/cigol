#pragma once

#include <cigol/ecs/scene.hpp>

namespace cigol::application {
    cigol::ecs::Scene
    makeMainScene(
        const unsigned width,
        const unsigned height
    );
}
