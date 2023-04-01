#include "OscNode.hpp"

OscNode::OscNode() : GUI_Node("Oscillator", {{"freq", ControlSignal}}, {{"out", ProcessingSignal}}),
    osc(*new Oscillator(DEFAULT_WAVEFORM, nullptr, 0.f)) {
        printf("Debug: OscNode created [%p]\n", this);
    }

OscNode::~OscNode() {
    delete &osc;
}

void OscNode::setInput(const Connection& connection) {
    assert(connection.inputNode == this);

    ControlSignalBlock * csb = connection.outputNode->getControlSignalBlock();

    printf("Debug: input set into %s, in = %p\n", this->title, csb);
    osc.setFrequencyInput(csb);
}

void OscNode::content() {
    GUI_Node::content();
}