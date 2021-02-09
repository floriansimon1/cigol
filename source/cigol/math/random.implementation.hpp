#pragma once

#include <cigol/math/random.hpp>

#include <map>
#include <algorithm>

namespace cigol::math::random {
    template<typename Integer>
    Reproducible<Integer>::Reproducible(
        Integer seed
    )
        : engine(seed)
    {}

    // See https://stackoverflow.com/questions/19036141/vary-range-of-uniform-int-distribution
    // and https://stackoverflow.com/questions/30103356/distributions-and-internal-state
    template<typename Integer>
    template <typename Distribution, typename... Parameters>
    Distribution
    Reproducible<Integer>::getDistribution(const Parameters... parameters) {
        return Distribution(parameters...);
    }

    template<typename Integer>
    bool
    Reproducible<Integer>::boolean(
        Probability     probability
    ) {
        auto distribution = this->getDistribution<std::bernoulli_distribution>(probability);

        return distribution(this->engine);
    }
}
