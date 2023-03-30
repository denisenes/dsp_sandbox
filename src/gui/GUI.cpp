#include "GUI.hpp"

std::map<std::string, GUI_Node*(*)()> available_nodes {
    {"Oscillator", []() -> GUI_Node* { return new GUI_Node("Oscillator", {}, {
        {"out", ProcessingSignal}
    }); }},
    {"Adder", []() -> GUI_Node* { return new GUI_Node("Adder", {
        {"in1", ProcessingSignal}, {"in2", ProcessingSignal}                                       // Input slots
    }, {
        {"out", ProcessingSignal}
    }); }},
    {"Output", []() -> GUI_Node* { return new GUI_Node("Output", {{"in", ProcessingSignal}}, {}); }},
};
std::vector<GUI_Node*> nodes;

bool Connection::operator==(const Connection &other) const {
    return inputNode == other.inputNode &&
            inputSlot == other.inputSlot &&
            outputNode == other.outputNode &&
            outputSlot == other.outputSlot;
}

namespace ImGui {

void ShowMainWindow() {
    static ImNodes::Ez::Context* context = ImNodes::Ez::CreateContext();
    IM_UNUSED(context);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoScrollbar | 
                             ImGuiWindowFlags_NoScrollWithMouse | 
                             ImGuiWindowFlags_NoTitleBar | 
                             ImGuiWindowFlags_NoResize |
                             ImGuiWindowFlags_NoMove;

    if (ImGui::Begin("ImNodes", nullptr, flags)) {

        ImGuiIO& io = ImGui::GetIO();
        ImGui::SetWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y));
        ImGui::SetWindowPos(ImVec2(0.f, 0.f));

        ImNodes::Ez::BeginCanvas();
        for (auto it = nodes.begin(); it != nodes.end();) {
            GUI_Node* node = *it;

            // Start rendering node
            if (ImNodes::Ez::BeginNode(node, node->title, &node->position, &node->selected)) {
                // Render input nodes first (order is important)
                ImNodes::Ez::InputSlots(node->inputSlots.data(), node->inputSlots.size());

                // Custom node content may go here
                //ImGui::Text("Content of %s", node->title);

                // Render output nodes first (order is important)
                ImNodes::Ez::OutputSlots(node->outputSlots.data(), node->outputSlots.size());

                // Store new connections when they are created
                Connection new_connection;
                if (ImNodes::GetNewConnection(&new_connection.inputNode, &new_connection.inputSlot,
                                              &new_connection.outputNode, &new_connection.outputSlot))
                {
                    ((GUI_Node*) new_connection.inputNode)->connections.push_back(new_connection);
                    ((GUI_Node*) new_connection.outputNode)->connections.push_back(new_connection);
                }

                // Render output connections of this node
                for (const Connection& connection : node->connections) {
                    // Node contains all it's connections (both from output and to input slots). This means that multiple
                    // nodes will have same connection. We render only output connections and ensure that each connection
                    // will be rendered once.
                    if (connection.outputNode != node) {
                        continue;
                    }

                    if (!ImNodes::Connection(connection.inputNode, connection.inputSlot, connection.outputNode,
                                             connection.outputSlot)) {
                        // Remove deleted connections
                        ((GUI_Node*) connection.inputNode)->DeleteConnection(connection);
                        ((GUI_Node*) connection.outputNode)->DeleteConnection(connection);
                    }
                }
            }
            
            ImNodes::Ez::EndNode();

            if (node->selected && ImGui::IsKeyPressedMap(ImGuiKey_Delete) && ImGui::IsWindowFocused()) {
                // Deletion order is critical: first we delete connections to us
                for (auto& connection : node->connections) {
                    if (connection.outputNode == node) {
                        ((GUI_Node*) connection.inputNode)->DeleteConnection(connection);
                    } else {
                        ((GUI_Node*) connection.outputNode)->DeleteConnection(connection);
                    }
                }
                node->connections.clear();
                
                delete node;
                it = nodes.erase(it);
            } else {
                ++it;
            }
        }

        if (ImGui::IsMouseReleased(1) && ImGui::IsWindowHovered() && !ImGui::IsMouseDragging(1)) {
            ImGui::FocusWindow(ImGui::GetCurrentWindow());
            ImGui::OpenPopup("NodesContextMenu");
        }

        if (ImGui::BeginPopup("NodesContextMenu")) {
            for (const auto& desc : available_nodes)
            {
                if (ImGui::MenuItem(desc.first.c_str()))
                {
                    nodes.push_back(desc.second());
                    ImNodes::AutoPositionNode(nodes.back());
                }
            }

            ImGui::Separator();
            if (ImGui::MenuItem("Reset Zoom")) {
                ImNodes::GetCurrentCanvas()->Zoom = 1;
            }

            if (ImGui::IsAnyMouseDown() && !ImGui::IsWindowHovered()) {
                ImGui::CloseCurrentPopup();
            }

            ImGui::EndPopup();
        }

        ImNodes::Ez::EndCanvas();
    }
    ImGui::End();
}

} // namespace ImGui