#include "ProcessingBlock.h"
#include "Jack.h"
#include "GlobalDecls.h"

class Adder : public ProcessingBlock {
    public:
        Adder(ProcessingBlock& in1, ProcessingBlock& in2)
         : ProcessingBlock() {
            inputs.push_back(&in1);
            inputs.push_back(&in2);
         }

    protected:
        sample_t process() {
            return (inputs[IN_1]->out() + inputs[IN_2]->out()) / 2.f;
        }
};