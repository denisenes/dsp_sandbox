#include "JackNode.hpp"

JackNode::JackNode() : GUI_Node("Jack", {{"in", ProcessingSignal}}, {}), jack(Jack::instance) {
    printf("Debug: JackNode created [%p]\n", this);
}

void JackNode::content() {
    GUI_Node::content();
    ImGui::Text("TEST");
}

void JackNode::setInput(const Connection& connection) {
    assert(connection.inputNode == this);
    ProcessingBlock * pb = connection.outputNode->getProcessingBlock();

    printf("Debug: input set into %s, in = %p\n", this->title, pb);
    jack.setInput(pb);
}