#include "ProcessingBlock.h"
#include "Jack.h"

class Adder : public ProcessingBlock {
    public:
        Adder(ProcessingBlock& in1, ProcessingBlock& in2)
         : ProcessingBlock(in1), input2(in2) {}

    private:
        ProcessingBlock& input2;

    protected:
        float process() {
            return (input.out() + input2.out()) / 2.f;
        }
};