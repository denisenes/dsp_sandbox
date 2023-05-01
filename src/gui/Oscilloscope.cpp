#include "Oscilloscope.hpp"

Oscilloscope::Oscilloscope() : 
            oscilloscope(*new OscilloscopeBlock()),
            GUI_Node("Oscilloscope", {{"in", ProcessingSignal}}, {{"out", ProcessingSignal}}) {};

Oscilloscope::~Oscilloscope() {
    delete &oscilloscope;
}

void Oscilloscope::setInput(const Connection& connection) {
    assert(connection.inputNode == this);

    if (!strcmp(connection.inputSlot, "in")) {
        ProcessingBlock * pb = connection.outputNode->getProcessingBlock();
        oscilloscope.setInput(pb);

        printf("Debug: input set into %s, in = %p\n", this->title, pb);
    } else {
        assert(false);
    }
}

void Oscilloscope::deleteInput(const Connection& connection) {
    assert(connection.inputNode == this);

    if (!strcmp(connection.inputSlot, "in")) {
        oscilloscope.setInput(nullptr);
    } else {
        assert(false);
    }
}

void Oscilloscope::content() {
    sample_t* buffer = oscilloscope.getBuffer();

    ImGui::PlotLines("", buffer, oscilloscope.getBufferSize(), 
        0, nullptr, 3.402823466e+38F, 3.402823466e+38F, ImVec2(200.f, 100.f));
}