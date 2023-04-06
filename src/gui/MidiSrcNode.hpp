#pragma once

#include "GUI.hpp"
#include "../processing/MidiSignalBlock.h"

class MidiSrcNode : public GUI_Node {
    public:
        MidiSrcNode();
        ~MidiSrcNode();

        void setInput(const Connection& connection);
        void content();

        ProcessingBlock*    getProcessingBlock() { return GUI_Node::getProcessingBlock(); }
        ControlSignalBlock* getControlSignalBlock() { return &midiBlock; }

    private:
        MidiSignalBlock& midiBlock;
};