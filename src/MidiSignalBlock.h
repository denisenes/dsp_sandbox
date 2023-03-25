#pragma once 

#include "ControlSignalBlock.h"
#include "Jack.h"
#include "Utils.h"

class MidiSignalBlock : public ControlSignalBlock {
    protected:
        sample_t generate() {
            if (!Jack::instance.isMidiNoteOn()) {
                return 0.f;
            }

            return getInputFrequency();
        }

    private:
        sample_t getInputFrequency() {
            unsigned char midiNote = Jack::instance.currentMidiNote();
            return Utils::noteToFreq(midiNote);
        }
};