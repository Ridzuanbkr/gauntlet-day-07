#pragma once

#include "RandomSource.hpp"

// Dice.hpp: before the refactor, untestable
class Dice {
    private:
        RandomSource& rng_;

    public:
        explicit Dice(RandomSource& rng) : rng_(rng) {}

            int roll() {
                return rng_.next(6) + 1;    // randomness baked in, so an exact CHECK is impossible
            }
    
};