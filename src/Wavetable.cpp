#include <math.h>
#include <algorithm>

#include "Utils.h"
#include "Jack.h"
#include "Wavetable.h"

#define HARMONICS_NUMBER 75 // TODO compute
// #define USE_BANDLIMITED_WAVES

void Wavetable::initTable(Waveform waveform) {
    switch (waveform) {
        // TODO implement
        case SAW:
            initSaw();
            break;
        case TRI:
            initTri();
            break;
        case SQR:
            initSqr();
            break;
        case SIN:
            initSin();
            break;
        default:
            break;
    }
}

inline void Wavetable::initSin() {
    int bound = tableLength;

    for (int i = 0; i < bound; i++) {
        table[i] = sin(2 * M_PI * i / bound);
    }
}

inline void Wavetable::initSqr() {
    #ifdef USE_BANDLIMITED_WAVES
        sample_t bound = static_cast<sample_t>(tableLength);
        sample_t normCoef = 4.f / M_PI;

        for (int t = 0; t < bound; t++) {
            for (sample_t k = 1.f; k <= HARMONICS_NUMBER; k += 1.f) {
                sample_t denom = 2 * k - 1;
                sample_t num   = sin(2 * M_PI * denom * t / bound);
                table[t] += num / denom;
            }
            table[t] *= normCoef;
        }
    #else
        int bound = tableLength;

        for (int i = 0; i < bound; i++) {
            table[i] = i < bound /2 ? 0 : 1;
        }
    #endif
}

inline void Wavetable::initSaw() {
    #ifdef USE_BANDLIMITED_WAVES
        sample_t bound = static_cast<sample_t>(tableLength);
        sample_t ampl = 1.f;
        sample_t normCoef = 2.f * ampl / M_PI;
        
        
        for (int t = 0; t < bound; t++) {
            for (sample_t k = 1.f; k <= HARMONICS_NUMBER; k += 1.f) {
                sample_t coeff = fmod(k, 2) <= 0.5f ? 1 : -1;
                table[t] += coeff * sin(2 * M_PI * k * t / bound) / (sample_t) k;
            }
            table[t] *= normCoef;
        }
    #else
        int bound = tableLength;

        for (int i = 0; i < bound; i++) {
            table[i] = -(1.0f / bound) * i + 1.0f;
        }
    #endif
}

inline void Wavetable::initTri() {
    int bound = tableLength;

    for (int i = 0; i < bound; i++) {
        int b = floorf(i / bound + 0.5f);
        table[i] = 2 * fabsf(i / bound - b);
    }
}

 sample_t Wavetable::getValue(sample_t frequency) {
    frequency = frequency < 0.f ? 0.f : frequency;

    readPtr += tableLength * frequency;

    while (readPtr >= tableLength) {
        readPtr -= tableLength;
    }

    sample_t x = readPtr; 
    sample_t x0 = floor(readPtr);
    sample_t x1 = x0 + 1;
    sample_t y0 = table[static_cast<int>(x0)];
    sample_t y1 = table[static_cast<int>(x1)];

    sample_t y = Utils::linearInterpolation(readPtr, x0, y0, x1, y1);

    return y;
}