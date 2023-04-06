#include "Oscillator.h"
#include <stdio.h>
#include "Utils.h"

sample_t Oscillator::process() {
    sample_t freq = getInputFrequency();

    if (freq < EPS) {
        return 0.f;
    }

    if (detuneParam != 0.0f) {
        sample_t sample1 = voice1.getValue(freq - freq * detuneParam);
        sample_t sample2 = voice2.getValue(freq + freq * detuneParam);
        
        return (sample1 + sample2) / 2.f; 
    } else {
        return voice1.getValue(freq);
    }
}

void Oscillator::setWaveform(Waveform w) {
    if (w == currentWaveform) {
        return;
    }

    currentWaveform = w;
    voice1.setWaveform(w);
    voice2.setWaveform(w);
}

Waveform Oscillator::getWaveform() {
    return currentWaveform;
}