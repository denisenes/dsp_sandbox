#include "ProcessingBlock.h"
#include "Jack.h"
#include "GlobalDecls.h"

class Adder : public ProcessingBlock {
    public:
        Adder(ProcessingBlock* in1, ProcessingBlock* in2)
         : ProcessingBlock() {
            inputs.push_back(in1);
            inputs.push_back(in2);
         }

        void setInput1(ProcessingBlock* pb1) {
            inputs[IN_1] = pb1;
        }

        void setInput2(ProcessingBlock* pb2) {
            inputs[IN_2] = pb2;
        }

    protected:
        sample_t process() {
            if (inputs[IN_1] == nullptr || inputs[IN_2] == nullptr) {
                return 0.f;
            }
            
            return (inputs[IN_1]->out() + inputs[IN_2]->out()) / 2.f;
        }
};