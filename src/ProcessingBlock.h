#ifndef PROC_BLOCK_H
#define PROC_BLOCK_H

#include "GlobalDecls.h"

class ProcessingBlock {
    public:
        ProcessingBlock(ProcessingBlock& in) : input(in) {}

        sample_t out() {
            return process();
        }

    protected:
        ProcessingBlock& input;
        virtual sample_t process() { return 0.f; };
};

#endif