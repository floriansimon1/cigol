#pragma once

#include <cigol/base/non-copyable.hpp>

#include <random>

namespace cigol::math::random {
    using Probability = double;

    template<typename Integer>
    class Reproducible: private cigol::base::NonCopyable {
        private:
            std::mt19937 engine;

            template <typename Distribution, typename... Parameters>
            Distribution
            getDistribution(const Parameters... parameters);
        
        public:
            Reproducible(
                Integer     seed
            );

            bool
            boolean(
                Probability probability
            );
    };
}


#include <cigol/math/random.implementation.hpp>
