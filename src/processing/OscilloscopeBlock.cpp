#include "OscilloscopeBlock.hpp"

void OscilloscopeBlock::swapBuffers() {
    currentBuffer.store(currentBuffer ^ 0x1);
}

sample_t* OscilloscopeBlock::getBuffer() {
    if (produced.load()) {
        swapBuffers();
        produced.store(false);
    }
    return buffers[currentBuffer.load() ^ 0x1];
}

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

        if (!produced.load()) {
            buffers[currentBuffer][current_buff_elem++] = inputWaveSample;

            if (current_buff_elem == BUFF_LEN) {
                produced.store(true);
                current_buff_elem = 0;
            }
        }
    }

    return inputWaveSample;
}
