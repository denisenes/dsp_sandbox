#pragma once

#include <jack/jack.h>
#include <jack/midiport.h>

#include <assert.h>
#include "ProcessingBlock.h"

#include <stdio.h>

class Jack {
    public:
        static Jack instance;

        Jack(const char* clientName);
        Jack(const char* clientName, jack_options_t options, jack_status_t* status);

        void setInput(ProcessingBlock * pb) {
            printf("TEST\n");
            input = pb;
        }

        jack_nframes_t getSampleRate() {
            assert(client != nullptr);
            return jack_get_sample_rate(client);
        }

        jack_port_t* getInputPort() {
            assert(input_port != nullptr);
            return input_port;
        }

        jack_port_t* getOutputPort() {
            assert(output_port != nullptr);
            return output_port;
        }

        sample_t isMidiNoteOn() {
            return note_on;
        }

        unsigned char currentMidiNote() {
            return note;
        }

        sample_t* getGain() {
            return &gain;
        }

        sample_t getPickedSignalValue() {
            return pickedSignalValue;
        }

        void portRegister(const char * portName, const char * portType, unsigned long flags, unsigned long bufferSize);

        void activate();

        void close();

        void assertInputBlock(const ProcessingBlock * pb) {
            assert(pb == input);
        }

    private:
        jack_client_t* client;
        ProcessingBlock * input;

        jack_port_t* input_port;
        jack_port_t*  output_port;

        sample_t gain;
        sample_t pickedSignalValue;

        static sample_t note_on;
        static unsigned char note;

        static int process(jack_nframes_t nframes, void* arg);
        static int sampleRateChanged(jack_nframes_t nframes, void *arg);
        static void shutdown(void *arg);

        void setProcessCallback(JackProcessCallback callback, void* arg) {
            assert(client != nullptr);
            jack_set_process_callback(client, callback, arg);
        }

        void setSampleRateCallback(JackSampleRateCallback callback, void* arg) {
            assert(client != nullptr);
            jack_set_sample_rate_callback(client, callback, arg);
        }

        void setOnShutdownCallback(JackShutdownCallback callback, void* arg) {
            assert(client != nullptr);
            jack_on_shutdown(client, callback, arg);
        }
};