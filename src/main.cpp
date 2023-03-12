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

void setup() {
	Oscillator& osc1 = *new Oscillator(SAW, 0.001f);
	Oscillator& osc2 = *new Oscillator(SIN, 0.008f);

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
