#pragma once

#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif

#include <vector>
#include <map>
#include <string>
#include <imgui.h>
#include <imgui_internal.h>
#include "ImNodesEz.h"

#include "../processing/ProcessingBlock.h"
#include "../processing/ControlSignalBlock.h"

#include <stdio.h>
#include <string>

/// A structure defining a connection between two slots of two nodes.
struct Connection {
    void *inputNode = nullptr;

    const char *inputSlot = nullptr;

    void *outputNode = nullptr;

    const char *outputSlot = nullptr;

    bool operator==(const Connection &other) const;
    
    bool operator!=(const Connection &other) const
    {
        return !operator==(other);
    }
};

enum NodeSlotTypes
{
    ProcessingSignal = 1,
    ControlSignal
};

struct GUI_Node {
    const char * title;
    bool selected = false;

    ImVec2 position{};

    std::vector<Connection> connections{};

    std::vector<ImNodes::Ez::SlotInfo> inputSlots{};
    std::vector<ImNodes::Ez::SlotInfo> outputSlots{};

    GUI_Node(const char * title,
                      const std::vector<ImNodes::Ez::SlotInfo>&& input_slots,
                      const std::vector<ImNodes::Ez::SlotInfo>&& output_slots) :
    title(title) {
        inputSlots = input_slots;
        outputSlots = output_slots;
    }

    void deleteConnection(const Connection& connection);
    void createConnection(const Connection& new_connection);

    virtual void setInput(const Connection& connection);
    virtual void content();

    virtual ProcessingBlock*    getProcessingBlock();
    virtual ControlSignalBlock* getControlSignalBlock();
};

namespace ImGui
{
    void ShowMainWindow();
}

extern std::vector<GUI_Node*> nodes;