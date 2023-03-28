#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include "GlobalDecls.h"

#define FREQS_NUM 128

class Utils {
    public:
        static sample_t noteToFreq(unsigned char note) {
            return frequencies[note];
        }

        static void calcFreqs(sample_t srate) { 
	        for(int i = 0; i < FREQS_NUM; i++) {
	        	frequencies[i] = 440.0f / 32.0f * pow(2, (((sample_t) i - 9.0f) / 12.0f)) / srate;
	        }
        }

        static sample_t linearInterpolation(sample_t x, sample_t x0, sample_t y0, sample_t x1, sample_t y1) {
            return y0 + (x - x0)*(y1 - y0)*(x1 - x0);
        }

        static sample_t frequencies[FREQS_NUM];
};

#endif