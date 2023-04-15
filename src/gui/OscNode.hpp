#pragma once

#include "GUI.hpp"
#include "../processing/Oscillator.h"

#include "imgui-knobs.h"

#define DEFAULT_WAVEFORM SIN

class OscNode : public GUI_Node {
    public:
        OscNode();
        ~OscNode();

        void setInput(const Connection& connection);
        void deleteInput(const Connection& connection);
        void content();

        ProcessingBlock*    getProcessingBlock() { return &osc; }
        ControlSignalBlock* getControlSignalBlock() { return GUI_Node::getControlSignalBlock(); }

    private:
        Oscillator& osc;

        int current_waveform_idx = 0;
        int flags = 0;
        sample_t detuneParam;
        sample_t pitchParam;
};