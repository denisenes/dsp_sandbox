#include "JackNode.hpp"

void JackNode::content() {
    GUI_Node::content();
    ImGui::Text("TEST");
}

void JackNode::setInput(const Connection& connection) {
    assert(connection.inputNode == this);
}