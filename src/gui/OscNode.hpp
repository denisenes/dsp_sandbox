#pragma once

#include "GUI.hpp"
#include "../processing/Oscillator.h"

#define DEFAULT_WAVEFORM SIN

class OscNode : public GUI_Node {
    public:
        OscNode();
        ~OscNode();

        void setInput(const Connection& connection);
        void content();

        ProcessingBlock*    getProcessingBlock() { return &osc; }
        ControlSignalBlock* getControlSignalBlock() { return GUI_Node::getControlSignalBlock(); }

    private:
        Oscillator& osc;
};