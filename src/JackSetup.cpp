#include "JackSetup.hpp"

void setup() {
	//NoiseGenerator& ng = *new NoiseGenerator();
	//StepSequencer& seq = *new StepSequencer(ng, 0.2f);

	//NoiseGenerator& ng2 = *new NoiseGenerator();
	//StepSequencer& seq2 = *new StepSequencer(ng2, 0.333f);

	MidiSignalBlock& midiBlock = *new MidiSignalBlock();
	
	//Oscillator& osc1 = *new Oscillator(SAW, seq, 0.002f);
	Oscillator& osc2 = *new Oscillator(SAW, midiBlock, 0.0f);

	//Adder& adder = *new Adder(osc1, osc2);

	Jack::instance.setInput(&osc2);
}

void jackSetup() {
	printf("Start JACK configuration\n");
	Utils::calcFreqs(Jack::instance.getSampleRate());

	Jack::instance.portRegister("midi_in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
	Jack::instance.portRegister("audio_out", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

	setup();
	Jack::instance.activate();
}

void jackOnTermination() {
	Jack::instance.close();
}