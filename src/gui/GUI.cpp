#include "GUI.hpp"

#include "SourceNode.hpp"
#include "OscNode.hpp"
#include "JackNode.hpp"
#include "AdderNode.hpp"

std::map<std::string, GUI_Node*(*)()> available_nodes {
    {"Oscillator", []() -> GUI_Node* { return new OscNode(); }},
    {"Adder", []() -> GUI_Node* { return new AdderNode(); }},
    {"Source", []() -> GUI_Node* { return new SourceNode(MIDI); }},
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

            if (ImNodes::Ez::BeginNode(node, node->title, &node->position, &node->selected)) {
                ImNodes::Ez::InputSlots(node->inputSlots.data(), node->inputSlots.size());

                node->content();

                ImNodes::Ez::OutputSlots(node->outputSlots.data(), node->outputSlots.size());

                // Connection creation
                Connection new_connection;
                void** inNodePtr  = reinterpret_cast<void**>(&new_connection.inputNode);
                void** outNodePtr = reinterpret_cast<void**>(&new_connection.outputNode);
                if (ImNodes::GetNewConnection(inNodePtr, &new_connection.inputSlot,
                                              outNodePtr, &new_connection.outputSlot))
                {
                    (new_connection.inputNode)->createConnection(new_connection);
                    (new_connection.outputNode)->createConnection(new_connection);
                }

                // Render output connections of this node
                for (const Connection& connection : node->connections) {
                    if (connection.outputNode != node) {
                        continue;
                    }

                    if (!ImNodes::Connection(connection.inputNode, connection.inputSlot, connection.outputNode,
                                             connection.outputSlot)) {
                        ((GUI_Node*) connection.inputNode)->deleteConnection(connection);
                        ((GUI_Node*) connection.outputNode)->deleteConnection(connection);
                    }
                }
            }
            
            ImNodes::Ez::EndNode();

            if (node->selected && ImGui::IsKeyPressedMap(ImGuiKey_Delete) && ImGui::IsWindowFocused()) {
                // Deletion order is critical: first we delete connections to us
                for (auto& connection : node->connections) {
                    if (connection.outputNode == node) {
                        ((GUI_Node*) connection.inputNode)->deleteConnection(connection);
                    } else {
                        ((GUI_Node*) connection.outputNode)->deleteConnection(connection);
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
            for (const auto& desc : available_nodes) {
                if (ImGui::MenuItem(desc.first.c_str())) {
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

void GUI_Node::deleteConnection(const Connection &connection) {
    for (auto it = connections.begin(); it != connections.end(); ++it) {
        if (connection == *it) {
            if (connection.inputNode == this) {
                deleteInput(connection);
            }
            
            connections.erase(it);
            break;
        }
    }
}

void GUI_Node::createConnection(const Connection &new_connection) {
    connections.push_back(new_connection);
    if (new_connection.inputNode == this) {
        setInput(new_connection);
    }
}

void GUI_Node::setInput(const Connection& connection) {
    // nop
}

void GUI_Node::deleteInput(const Connection& connection) {
    // nop
}

void GUI_Node::content() {
    ImGui::Text("%s", this->title);
}

ProcessingBlock* GUI_Node::getProcessingBlock() {
    return nullptr;
}

ControlSignalBlock* GUI_Node::getControlSignalBlock() {
    return nullptr;
}