#include "JackSetup.hpp"

void jackSetup() {
	printf("Start JACK configuration\n");
	Utils::calcFreqs(Jack::instance.getSampleRate());

	Jack::instance.portRegister("midi_in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
	Jack::instance.portRegister("audio_out", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

	Jack::instance.activate();
}

void jackOnTermination() {
	Jack::instance.close();
}