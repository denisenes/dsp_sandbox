#include "AdderNode.hpp"

#include <string.h>

AdderNode::AdderNode() : GUI_Node("Adder", {{"in1", ProcessingSignal}, {"in2", ProcessingSignal}}, {{"out", ProcessingSignal}}),
    adder(*new Adder(nullptr, nullptr)) {
        printf("Debug: Adder created [%p]\n", this);
}

AdderNode::~AdderNode() {
    delete &adder;
}

void AdderNode::setInput(const Connection& connection) {
    assert(connection.inputNode == this);

    ProcessingBlock * pb = connection.outputNode->getProcessingBlock();

    if (strcmp(connection.inputSlot, "in1")) {
        adder.setInput1(pb);
    } else if (strcmp(connection.inputSlot, "in2")) {
        adder.setInput2(pb);
    }
    
}

void AdderNode::deleteInput(const Connection& connection) {
    assert(connection.inputNode == this);

    if (strcmp(connection.inputSlot, "in1")) {
        adder.setInput1(nullptr);
    } else if (strcmp(connection.inputSlot, "in2")) {
        adder.setInput2(nullptr);
    }
}

void AdderNode::content() {
    
}