#pragma once

#include "GUI.hpp"
#include "OscilloscopeBlock.hpp"

class Oscilloscope : public GUI_Node {
    public:
        Oscilloscope();
        ~Oscilloscope();

        void setInput(const Connection& connection);
        void deleteInput(const Connection& connection);
        void content();

        ProcessingBlock*    getProcessingBlock() { return &oscilloscope; }
        ControlSignalBlock* getControlSignalBlock() { return GUI_Node::getControlSignalBlock(); }

    private:
        OscilloscopeBlock& oscilloscope;
};