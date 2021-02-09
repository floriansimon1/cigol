#include <cigol/application/generate-base-image.hpp>

#include <cigol/math/random.hpp>

namespace cigol::application {
    const std::vector<std::byte>
    generateBaseState(
        const unsigned width,
        const unsigned height
    ) {
        std::vector<std::byte>                      pixels(width * height * 3);
        cigol::math::random::Reproducible<unsigned> generator(5);

        for (size_t i = 0; i < pixels.size(); i += 3) {
            const bool alive = generator.boolean(0.05);

            pixels[i] = pixels[i + 1] = pixels[i + 2] = alive ? std::numeric_limits<std::byte>::max() : std::numeric_limits<std::byte>::min();
        }

        return pixels;
    }
}