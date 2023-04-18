#pragma once 

#include "ControlSignalBlock.h"
#include "Utils.h"
#include "Jack.h"

class ConstSignalBlock : public ControlSignalBlock {
    public:
        ConstSignalBlock(sample_t v) {
            value = v;
        }

    protected:
        sample_t generate() {
            return getConstValue() / Jack::instance.getSampleRate();
        }

    private:
        sample_t value;

        sample_t getConstValue() {
            return value;
        }

        void setConstValue(sample_t v) {
            value = v;
        }
};