#pragma once

#include "GlobalDecls.h"

class ControlSignalBlock {
    public:
        sample_t out() {
            return generate();
        }

    protected:
        virtual sample_t generate() {
            return 0.f;
        }
};