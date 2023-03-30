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

#include <stdio.h>

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

struct GUI_Node
{
    const char *title = nullptr;
    bool selected = false;

    ImVec2 position{};

    std::vector<Connection> connections{};

    std::vector<ImNodes::Ez::SlotInfo> inputSlots{};
    std::vector<ImNodes::Ez::SlotInfo> outputSlots{};

    explicit GUI_Node(const char *title,
                      const std::vector<ImNodes::Ez::SlotInfo> &&input_slots,
                      const std::vector<ImNodes::Ez::SlotInfo> &&output_slots)
    {
        title = title;
        inputSlots = input_slots;
        outputSlots = output_slots;
    }

    void DeleteConnection(const Connection &connection)
    {
        for (auto it = connections.begin(); it != connections.end(); ++it)
        {
            if (connection == *it)
            {
                connections.erase(it);
                break;
            }
        }
    }
};

namespace ImGui
{
    void ShowMainWindow();
}