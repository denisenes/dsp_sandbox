#include "SourceNode.hpp"

SourceNode::SourceNode(SourceType type) : GUI_Node("MIDI Source", {}, {{"out", ControlSignal}}),
    midiBlock(*new MidiSignalBlock()), constBlock(*new ConstSignalBlock(440.f)) {
        sourceType = type;
        printf("Debug: SourceNode created [%p]\n", this);
    }

SourceNode::~SourceNode() {
    delete &midiBlock;
}

ControlSignalBlock* SourceNode::getControlSignalBlock() {
    switch (sourceType) {
        case MIDI:
            return &midiBlock;
        case CONST:
            return &constBlock;
        default:
            assert(false);
    }
}

void SourceNode::setInput(const Connection& connection) {
    assert(false);
    GUI_Node::setInput(connection);
}

const char* types[3] = { "midi", "const", "noise" }; 

void SourceNode::content() {
    const char* type_preview = types[sourceType];

    ImGui::PushItemWidth(100.f); 
    if (ImGui::BeginCombo("type", type_preview, 0)) {
        for (int n = 0; n < IM_ARRAYSIZE(types); n++) {
            const bool is_selected = (sourceType == n);
            if (ImGui::Selectable(types[n], is_selected))
                sourceType = static_cast<SourceType>(n);
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
    ImGui::PopItemWidth();

    switch (sourceType) {
    case CONST:

        break;
    case MIDI:
        // nothing to draw
        break;
    default:
        break;
    }
}