#pragma once

#include "ProcessingBlock.h"
#include "Jack.h"
#include "GlobalDecls.h"
#include "GlobalClock.h"

#include "Utils.h"

#define BUFF_LEN 1024

class OscilloscopeBlock : public ProcessingBlock {
    public:
        OscilloscopeBlock() : ProcessingBlock(), startTime(0ll) {
            targetFrequency = 440.f;
            smp_time_t samplesPerWave = static_cast<smp_time_t>(Utils::getSampleRate() / targetFrequency);
            sampleStepDuration = samplesPerWave / BUFF_LEN;
            
            inputs[IN_1] = nullptr;
        }

        sample_t* getBuffer();

        int getBufferSize() {
            return BUFF_LEN;
        }

        void setInput(ProcessingBlock * pb) {
            inputs[IN_1] = pb;
        }

    protected:
        sample_t process();

    private:
        int currentBuffer = 0;
        sample_t buffers[2][BUFF_LEN];

        sample_t targetFrequency;
        smp_time_t sampleStepDuration;
        smp_time_t startTime;
};