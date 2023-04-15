#pragma once

#include "ProcessingBlock.h"
#include "ControlSignalBlock.h"
#include "Jack.h"
#include "GlobalDecls.h"
#include "Wavetable.h"

#include "Utils.h"

#define DEFAULT_OSC_TABLE_LENGTH 512

class Oscillator : public ProcessingBlock {
    public:
        Oscillator(Waveform w, ControlSignalBlock* freqInput, sample_t detune) : 
            ProcessingBlock(), currentWaveform(w),
            voice1(w, DEFAULT_OSC_TABLE_LENGTH), voice2(w, DEFAULT_OSC_TABLE_LENGTH),
            detuneParam(detune), frequencyInput(freqInput) {
                assert(0.f <= detune && detune <= 1.f);
            } 
        
        void setFrequencyInput(ControlSignalBlock * csb) {
            frequencyInput = csb;
        }

        void setWaveform(Waveform w);
        Waveform getWaveform();
        void setDetune(sample_t param);

    private:
        Waveform currentWaveform;
        Wavetable voice1;
        Wavetable voice2;

        sample_t detuneParam;

        ControlSignalBlock* frequencyInput;

        sample_t getInputFrequency() {
            return frequencyInput == nullptr ? 0.f : frequencyInput->out();
        }

    protected:
        float process();
};