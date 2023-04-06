#include "JackNode.hpp"

#include "imgui-knobs.h"

JackNode::JackNode() : GUI_Node("Jack", {{"in", ProcessingSignal}}, {}), jack(Jack::instance) {
    printf("Debug: JackNode created [%p]\n", this);
}

void JackNode::content() {
    ImGui::ProgressBar(jack.getPickedSignalValue(), ImVec2(150.0f, 0.0f));
    ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x);
    ImGui::Text("level");

    ImGuiKnobs::Knob("Gain", jack.getGain(), -32.0f, 6.0f, 0.1f, "%.1fdB", ImGuiKnobVariant_Stepped);
}

void JackNode::setInput(const Connection& connection) {
    assert(connection.inputNode == this);
    ProcessingBlock * pb = connection.outputNode->getProcessingBlock();

    printf("Debug: input set into %s, in = %p\n", this->title, pb);
    jack.setInput(pb);
}

void JackNode::deleteInput(const Connection& connection) {
    assert(connection.inputNode == this);
    jack.assertInputBlock(connection.outputNode->getProcessingBlock());

    printf("Debug: remove input from %s\n", this->title);
    jack.setInput(nullptr);
}