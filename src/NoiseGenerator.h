#pragma once

#include "ProcessingBlock.h"
#include "ControlSignalBlock.h"
#include "Jack.h"
#include <cstdlib>

class NoiseGenerator : public ProcessingBlock, public ControlSignalBlock {
    public:
        NoiseGenerator() : ProcessingBlock(*this) {}

    protected:
        sample_t process() {
            float randVal = static_cast<float>(std::rand());
            return 2.f * (randVal / (float) RAND_MAX) - 1.f;
        }

        sample_t generate() {
            float randVal = static_cast<float>(std::rand());
            printf("%f\n", std::fmod(randVal, Jack::instance.getSampleRate() / 2.f));
            return std::fmod(randVal, Jack::instance.getSampleRate() / 2.f);
        }
};