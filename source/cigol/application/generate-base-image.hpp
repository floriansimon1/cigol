#pragma once

#include <vector>

namespace cigol::application {
    const std::vector<std::byte>
    generateBaseState(
        const unsigned width,
        const unsigned height
    );
}
