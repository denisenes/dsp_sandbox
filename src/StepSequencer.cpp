#include "StepSequencer.h"
#include <stdio.h>

sample_t StepSequencer::generate() {
    smp_time_t current_time = GlobalClock::getGlobalTime();

    if (stepStartTime + stepDuration <= current_time) {
        currentFrequency = sequenceInput.out();
        stepStartTime = current_time;
        //printf("Freq: %f\n", currentFrequency);
    }

    return currentFrequency;
}