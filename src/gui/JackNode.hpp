#pragma once

#include "GUI.hpp"
#include "../processing/Jack.h"

class JackNode : public GUI_Node {
    public:
        JackNode();
        ~JackNode() {};

        void setInput(const Connection& connection);
        void deleteInput(const Connection& connection);
        void content();

        ProcessingBlock*    getProcessingBlock() { return GUI_Node::getProcessingBlock(); }
        ControlSignalBlock* getControlSignalBlock() { return GUI_Node::getControlSignalBlock(); }
    private:
        Jack& jack;
};