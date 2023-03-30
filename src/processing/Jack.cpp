#include "Jack.h"
#include "Utils.h"
#include "GlobalClock.h"
#include <iostream>

Jack Jack::instance("bebra");
sample_t Jack::note_on;
unsigned char Jack::note;

Jack::Jack(const char* clientName) : Jack(clientName, JackNullOption, nullptr) {};

Jack::Jack(const char* clientName, jack_options_t options, jack_status_t* status) {
    client = jack_client_open(clientName, options, status);
    if (client == nullptr) {
        std::cerr << "Couldn't initialize JACK client" << std::endl;
        exit(1);
    }
    printf("Client created successfully\n");

    Jack::setProcessCallback(Jack::process, nullptr);
    Jack::setOnShutdownCallback(Jack::shutdown, nullptr);
    Jack::setSampleRateCallback(Jack::sampleRateChanged, nullptr);
}

void Jack::activate() {
    assert(client != nullptr);
    int res = jack_activate(client);
    if (res != 0) {
        std::cerr << "Couldn't activate JACK client" << std::endl;
    }
}

void Jack::close() {
    assert(client != nullptr);
    int res = jack_client_close(client);
    if (res != 0) {
        std::cerr << "Couldn't close JACK client" << std::endl;
    }
}

void Jack::portRegister(const char * portName, const char * portType, unsigned long flags, unsigned long bufferSize) {
    assert(client != nullptr);
    if (flags == JackPortIsInput) {
        input_port = jack_port_register(client, portName, portType, flags, bufferSize);  
    }
    if (flags == JackPortIsOutput) {
        output_port = jack_port_register(client, portName, portType, flags, bufferSize);
    }
}

int Jack::sampleRateChanged(jack_nframes_t nframes, void *arg) {
	printf("The sample rate is now %" PRIu32 "/sec\n", nframes);
	Utils::calcFreqs((sample_t) nframes);
	return 0;
}

void Jack::shutdown(void *arg) {
	exit(1);
}

int Jack::process(jack_nframes_t nframes, void* arg) {
    void* port_buf = jack_port_get_buffer(Jack::instance.getInputPort(), nframes);
	sample_t* out = (sample_t*) jack_port_get_buffer(Jack::instance.getOutputPort(), nframes);

    jack_midi_event_t in_event;
	jack_nframes_t event_index = 0;
	jack_nframes_t event_count = jack_midi_get_event_count(port_buf);

    if(event_count > 1) {
		printf(" midisine: have %d events\n", event_count);
		for(jack_nframes_t i = 0; i < event_count; i++) {
			jack_midi_event_get(&in_event, port_buf, i);
			printf("    event %d time is %d. 1st byte is 0x%x\n", i, in_event.time, *(in_event.buffer));
		}
	}

	jack_midi_event_get(&in_event, port_buf, 0);

    for (jack_nframes_t i = 0; i < nframes; i++) {
        if((in_event.time == i) && (event_index < event_count)) {
			if( ((*(in_event.buffer) & 0xf0)) == 0x90 ) {
				Jack::note = *(in_event.buffer + 1);
				Jack::note_on = 1.0;
			} else if( (*(in_event.buffer) & 0xf0) == 0x80 ) {
				Jack::note = *(in_event.buffer + 1);
				Jack::note_on = 0.0;
			}

			event_index++;
			if(event_index < event_count) {
				jack_midi_event_get(&in_event, port_buf, event_index);
			}
		}

        ProcessingBlock * in = instance.input;

        out[i] = in == nullptr ? 0.f : in->out();
        GlobalClock::tick();
    }

    return 0;
}