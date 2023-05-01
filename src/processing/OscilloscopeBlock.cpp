#include "OscilloscopeBlock.hpp"

sample_t* OscilloscopeBlock::getBuffer() {
    return buffers[currentBuffer];
}

/// @brief 
/// @return 
sample_t OscilloscopeBlock::process() {
    static int current_buff_elem = 0;
    smp_time_t current_time = GlobalClock::getGlobalTime();
    assert(current_buff_elem < BUFF_LEN);

    sample_t inputWaveSample;
    if (inputs[IN_1] != nullptr) {
        inputWaveSample = inputs[IN_1]->out();
    } else {
        inputWaveSample =  0.f;
    }

    if (startTime + sampleStepDuration <= current_time) {
        startTime = current_time;
        buffers[currentBuffer][current_buff_elem++] = inputWaveSample;

        if (current_buff_elem == BUFF_LEN) {
            currentBuffer ^= 0x1;
            current_buff_elem = 0;
        }
    }

    return inputWaveSample;
}
