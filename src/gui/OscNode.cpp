#include "OscNode.hpp"

const char* waveNames[4] {
    "sin", "tri", "sqr", "saw"
};

std::map<std::string, Waveform> availableWaveforms {
    {waveNames[0], Waveform::SIN},
    {waveNames[1], Waveform::TRI},
    {waveNames[2], Waveform::SQR},
    {waveNames[3], Waveform::SAW}
};

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

void OscNode::deleteInput(const Connection& connection) {
    assert(connection.inputNode == this);

    printf("Debug: remove input from %s, input=%s\n", this->title, connection.inputSlot);
    if (!strcmp(connection.inputSlot, "freq")) {
        osc.setFrequencyInput(nullptr);
    } else {
        assert(false);
    }
}

void OscNode::content() {
    const char* combo_preview_value = waveNames[current_waveform_idx];  // Pass in the preview value visible before opening the combo (it could be anything)
    
    ImGui::PushItemWidth(100.f); 
    if (ImGui::BeginCombo("waveform", combo_preview_value, flags)) {
        for (int n = 0; n < IM_ARRAYSIZE(waveNames); n++) {
            const bool is_selected = (current_waveform_idx == n);
            if (ImGui::Selectable(waveNames[n], is_selected))
                current_waveform_idx = n;

            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
    ImGui::PopItemWidth();

    Waveform current_waveform = availableWaveforms[waveNames[current_waveform_idx]];
    if (current_waveform != osc.getWaveform()) {
        osc.setWaveform(current_waveform);
        printf("DEBUG: waveform set from %d to %d\n", osc.getWaveform(), current_waveform);
    }

    ImGuiKnobs::Knob("detune", &detuneParam, 0.f, 50.f, 0.2f, "%.f", ImGuiKnobVariant_Wiper, 30.f);
    osc.setDetune(detuneParam);

    ImGui::SameLine(0.f);

    ImGuiKnobs::Knob("pitch", &pitchParam, -12.f, 12.f, 0.2f, "%.1f", ImGuiKnobVariant_Wiper, 30.f);
}