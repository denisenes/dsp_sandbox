#pragma once

#include "GUI.hpp"
#include "Adder.h"

class AdderNode : public GUI_Node {
    public :
        AdderNode();
        ~AdderNode();

        void setInput(const Connection& connection);
        void deleteInput(const Connection& connection);
        void content();

        ProcessingBlock*    getProcessingBlock() { return &adder; }
        ControlSignalBlock* getControlSignalBlock() { return GUI_Node::getControlSignalBlock(); }

    private:
        Adder& adder;
};