#include "MidiSrcNode.hpp"

MidiSrcNode::MidiSrcNode() : GUI_Node("MIDI Source", {}, {{"out", ControlSignal}}),
    midiBlock(*new MidiSignalBlock()) {
        printf("Debug: MidiSrcNode created [%p]\n", this);
    }

MidiSrcNode::~MidiSrcNode() {
    delete &midiBlock;
}

void MidiSrcNode::setInput(const Connection& connection) {
    GUI_Node::setInput(connection);
}

void MidiSrcNode::content() {
    GUI_Node::content();
}