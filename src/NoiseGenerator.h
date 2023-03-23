#pragma once

#include "ProcessingBlock.h"
#include <cstdlib>

class NoiseGenerator : public ProcessingBlock {
    public:
        NoiseGenerator() : ProcessingBlock(*this) {}

    protected:
        float process() {
            float randVal = static_cast<float>(std::rand());
            return 2.f * (randVal / (float) RAND_MAX) - 1.f;
        }

};