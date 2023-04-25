#pragma once

#include "GUI.hpp"
#include "MidiSignalBlock.h"
#include "ConstSignalBlock.h"

enum SourceType {
    MIDI,
    CONST,
    NOISE
};

class SourceNode : public GUI_Node {
    public:
        SourceNode(SourceType type);
        ~SourceNode();

        void setInput(const Connection& connection);
        void content();

        ProcessingBlock*    getProcessingBlock() { return GUI_Node::getProcessingBlock(); }
        ControlSignalBlock* getControlSignalBlock();

        void setSourceType(SourceType type) {
            sourceType = type;
        }

        SourceType getSourceType() {
            return sourceType;
        }

    private:
        SourceType sourceType;

        MidiSignalBlock& midiBlock;
        ConstSignalBlock& constBlock;

        void updateSourceType();
};