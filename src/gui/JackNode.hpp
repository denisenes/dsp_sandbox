#pragma once

#include "GUI.hpp"
#include "../processing/Jack.h"

class JackNode : public GUI_Node {
    public:
        JackNode() : GUI_Node("Jack", {{"in", ProcessingSignal}}, {}), jack(Jack::instance) {};

        virtual void setInput(const Connection& connection);
        virtual void content();

        virtual ProcessingBlock*    getProcessingBlock() { return GUI_Node::getProcessingBlock(); }
        virtual ControlSignalBlock* getControlSignalBlock() { return GUI_Node::getControlSignalBlock(); }
    private:
        Jack& jack;
};