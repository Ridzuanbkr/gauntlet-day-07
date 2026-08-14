#pragma once

class RandomSource {
    public:
        virtual ~RandomSource() = default;
        virtual int next(int max) = 0;
};