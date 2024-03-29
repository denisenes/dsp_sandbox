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

void SourceNode::updateSourceType() {
    for (Connection conn : this->connections) {
        if (conn.outputNode == this && !strcmp(conn.outputSlot, "out")) {
            printf("TEST\n");
            GUI_Node * inNode = conn.inputNode;
            inNode->setInput(conn);
        }
    }
}

void SourceNode::content() {
    const char* type_preview = types[sourceType];

    ImGui::PushItemWidth(100.f); 
    if (ImGui::BeginCombo("type", type_preview, 0)) {
        for (int n = 0; n < IM_ARRAYSIZE(types); n++) {
            const bool is_selected = (sourceType == n);

            if (ImGui::Selectable(types[n], is_selected)) {
                sourceType = static_cast<SourceType>(n);
                updateSourceType();
                printf("Debug: SourceNode source type changed [%p] to %d\n", this, sourceType);
            }

            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
    ImGui::PopItemWidth();

    switch (sourceType) {
    case CONST:
        ImGuiKnobs::Knob("freq", &currentFreq, 50.f, 5000.f, 1.f, "%.f", ImGuiKnobVariant_Wiper, 30.f);
        constBlock.setConstValue(currentFreq);
        break;
    case MIDI:
        // nothing to draw
        break;
    default:
        break;
    }
}