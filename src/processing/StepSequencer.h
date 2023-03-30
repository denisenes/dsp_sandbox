#pragma once

#include "ControlSignalBlock.h"
#include "GlobalDecls.h"
#include "GlobalClock.h"
#include "Jack.h"

class StepSequencer : public ControlSignalBlock {
    public:
        StepSequencer(ControlSignalBlock& input, raw_time_t stepDuration) : 
            stepStartTime(0ll), 
            currentFrequency(0.f), 
            sequenceInput(input)
            {
                sample_t sample_rate = static_cast<raw_time_t>(Jack::instance.getSampleRate());
                this->stepDuration = static_cast<smp_time_t>(stepDuration * sample_rate);
            };
    
    protected:
        sample_t generate();

    private:
        smp_time_t stepDuration;
        smp_time_t stepStartTime;
        sample_t currentFrequency;
        ControlSignalBlock& sequenceInput;
};