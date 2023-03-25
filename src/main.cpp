#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <jack/jack.h>
#include <jack/midiport.h>

#include "Jack.h"
#include "Adder.h"
#include "Oscillator.h"
#include "Utils.h"
#include "NoiseGenerator.h"
#include "MidiSignalBlock.h"
#include "StepSequencer.h"

void setup() {
	NoiseGenerator& ng = *new NoiseGenerator();
	StepSequencer& seq = *new StepSequencer(ng, 0.25f);
	MidiSignalBlock& midiBlock = *new MidiSignalBlock();
	
	Oscillator& osc1 = *new Oscillator(SAW, seq, 0.002f);
	Oscillator& osc2 = *new Oscillator(SIN, midiBlock, 0.005f);

	Adder& adder = *new Adder(osc1, osc2);

	Jack::instance.setInput(&adder);
}

int main(int narg, char **args) {
	printf("Start configuration\n");
	Utils::calcFreqs(Jack::instance.getSampleRate());

	Jack::instance.portRegister("midi_in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
	Jack::instance.portRegister("audio_out", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

	setup();
	Jack::instance.activate();

	/* run until interrupted */
	while(1) {
		sleep(10);
	}

	Jack::instance.close();
	return 0;
}
