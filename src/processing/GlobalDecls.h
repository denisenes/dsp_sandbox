#pragma once

#include <jack/jack.h>
#include <stdint.h>

typedef jack_default_audio_sample_t sample_t;

typedef uint64_t smp_time_t;
typedef float    raw_time_t; // sec