#pragma once

#include "GlobalDecls.h"
#include <vector>

#define IN_1 0
#define IN_2 1

#define MAX_INPUTS 2

class ProcessingBlock {
    public:
        ProcessingBlock() : inputs(MAX_INPUTS) {}

        sample_t out() {
            return process();
        }

    protected:
        std::vector<ProcessingBlock*> inputs;
        virtual sample_t process() { return 0.f; };
};