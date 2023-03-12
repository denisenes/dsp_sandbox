#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "ProcessingBlock.h"
#include "Jack.h"
#include "GlobalDecls.h"
#include "Wavetable.h"

#define DEFAULT_OSC_TABLE_LENGTH 512

class Oscillator : public ProcessingBlock {
    public:
        Oscillator(Waveform w, sample_t detune) : ProcessingBlock(*this), 
            voice1(w, DEFAULT_OSC_TABLE_LENGTH),
            voice2(w, DEFAULT_OSC_TABLE_LENGTH),
            detuneParam(detune) {
                assert(0.f <= detune && detune <= 1.f);
            } 

    private:
        Wavetable voice1;
        Wavetable voice2;

        sample_t detuneParam;

    protected:
        float process();
};

#endif