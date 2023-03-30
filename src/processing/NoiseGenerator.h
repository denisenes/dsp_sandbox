#pragma once

#include "ProcessingBlock.h"
#include "ControlSignalBlock.h"
#include "Jack.h"
#include <cstdlib>

#define MAX_GENERATED_NOTE 128;

class NoiseGenerator : public ProcessingBlock, public ControlSignalBlock {
    public:
        NoiseGenerator() : ProcessingBlock() {}

    protected:
        sample_t process() {
            float randVal = static_cast<float>(std::rand());
            return 2.f * (randVal / (float) RAND_MAX) - 1.f;
        }

        sample_t generate() {
            int note = std::rand() % MAX_GENERATED_NOTE;
            //printf("%f\n", std::fmod(randVal, Jack::instance.getSampleRate() / 2.f));
            return Utils::noteToFreq(note);
        }
};