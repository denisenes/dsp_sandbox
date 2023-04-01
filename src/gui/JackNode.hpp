#pragma once

#include "GUI.hpp"
#include "../processing/Jack.h"

class JackNode : public GUI_Node {
    public:
        JackNode();
        ~JackNode() {};

        virtual void setInput(const Connection& connection);
        virtual void content();

        ProcessingBlock*    getProcessingBlock() { return GUI_Node::getProcessingBlock(); }
        ControlSignalBlock* getControlSignalBlock() { return GUI_Node::getControlSignalBlock(); }
    private:
        Jack& jack;
};