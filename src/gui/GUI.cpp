#include "GUI.hpp"

std::map<std::string, MyNode*(*)()> available_nodes {
    {"Oscillator", []() -> MyNode* { return new MyNode("Oscillator", {}, {
        {"out", ProcessingSignal}
    }); }},
    {"Adder", []() -> MyNode* { return new MyNode("Adder", {
        {"in1", ProcessingSignal}, {"in2", ProcessingSignal}                                       // Input slots
    }, {
        {"out", ProcessingSignal}
    }); }},
    {"Output", []() -> MyNode* { return new MyNode("Output", {{"in", ProcessingSignal}}, {}); }},
};
std::vector<MyNode*> nodes;

namespace ImGui {

void ShowMainWindow(bool*) {
    // Canvas must be created after ImGui initializes, because constructor accesses ImGui style to configure default colors.
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

        // We probably need to keep some state, like positions of nodes/slots for rendering connections.
        ImNodes::Ez::BeginCanvas();
        for (auto it = nodes.begin(); it != nodes.end();) {
            MyNode* node = *it;

            // Start rendering node
            if (ImNodes::Ez::BeginNode(node, node->Title, &node->Pos, &node->Selected)) {
                // Render input nodes first (order is important)
                ImNodes::Ez::InputSlots(node->InputSlots.data(), node->InputSlots.size());

                // Custom node content may go here
                ImGui::Text("Content of %s", node->Title);

                // Render output nodes first (order is important)
                ImNodes::Ez::OutputSlots(node->OutputSlots.data(), node->OutputSlots.size());

                // Store new connections when they are created
                Connection new_connection;
                if (ImNodes::GetNewConnection(&new_connection.InputNode, &new_connection.InputSlot,
                                              &new_connection.OutputNode, &new_connection.OutputSlot))
                {
                    ((MyNode*) new_connection.InputNode)->Connections.push_back(new_connection);
                    ((MyNode*) new_connection.OutputNode)->Connections.push_back(new_connection);
                }

                // Render output connections of this node
                for (const Connection& connection : node->Connections) {
                    // Node contains all it's connections (both from output and to input slots). This means that multiple
                    // nodes will have same connection. We render only output connections and ensure that each connection
                    // will be rendered once.
                    if (connection.OutputNode != node) {
                        continue;
                    }

                    if (!ImNodes::Connection(connection.InputNode, connection.InputSlot, connection.OutputNode,
                                             connection.OutputSlot)) {
                        // Remove deleted connections
                        ((MyNode*) connection.InputNode)->DeleteConnection(connection);
                        ((MyNode*) connection.OutputNode)->DeleteConnection(connection);
                    }
                }
            }
            // Node rendering is done. This call will render node background based on size of content inside node.
            ImNodes::Ez::EndNode();

            if (node->Selected && ImGui::IsKeyPressedMap(ImGuiKey_Delete) && ImGui::IsWindowFocused()) {
                // Deletion order is critical: first we delete connections to us
                for (auto& connection : node->Connections) {
                    if (connection.OutputNode == node) {
                        ((MyNode*) connection.InputNode)->DeleteConnection(connection);
                    } else {
                        ((MyNode*) connection.OutputNode)->DeleteConnection(connection);
                    }
                }
                // Then we delete our own connections, so we don't corrupt the list
                node->Connections.clear();
                
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