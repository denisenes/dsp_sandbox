#include "ProcessingBlock.h"
#include "Jack.h"
#include "GlobalDecls.h"

class Adder : public ProcessingBlock {
    public:
        Adder(ProcessingBlock& in1, ProcessingBlock& in2)
         : ProcessingBlock(in1), input2(in2) {}

    private:
        ProcessingBlock& input2;

    protected:
        sample_t process() {
            return (input.out() + input2.out()) / 2.f;
        }
};