#include "Oscillator.h"
#include <stdio.h>
#include "Utils.h"

float Oscillator::process() {
    sample_t freq = Jack::instance.getInputFrequency();
    if (detuneParam != 0.0f) {
        sample_t sample1 = voice1.getValue(freq - freq * detuneParam);
        sample_t sample2 = voice2.getValue(freq + freq * detuneParam);
        
        return (sample1 + sample2) / 2.f; 
    } else {
        return voice1.getValue(freq);
    }
}