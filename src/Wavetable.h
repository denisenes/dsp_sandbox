#ifndef WAVETABLE_H
#define WAVETABLE_H

#include "GlobalDecls.h"
#include <math.h>

enum Waveform {
    SIN,
    TRI,
    SAW,
    SQR
};

class Wavetable {
    public:
        Wavetable(Waveform waveform, int length) {
            readPtr = 0.f;
            tableLength = length;
            table = new sample_t[length];
            initTable(waveform);
        }

        sample_t getValue(sample_t frequency);

    private:
        sample_t readPtr;

        int tableLength;
        sample_t * table;

        void initTable(Waveform waveform);

        void initSin();
        void initSqr();
        void initSaw();
        void initTri();
};

#endif