#pragma once

#include <math.h>
#include <stdio.h>

#include <jack/jack.h>
#include <jack/midiport.h>

#include "processing/Jack.h"
#include "processing/Adder.h"
#include "processing/Oscillator.h"
#include "processing/Utils.h"
#include "processing/NoiseGenerator.h"
#include "processing/MidiSignalBlock.h"
#include "processing/StepSequencer.h"

void jackSetup();
void jackOnTermination();