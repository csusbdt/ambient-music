#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>
#include "Sound.h"

using namespace std;

const double Sound::PI = 3.141592653589793238462;
const double Sound::PHI = 1.61803398875;
const double Sound::E = 2.718281828459;
const unsigned int Sound::samplesPerSecond = 48000;

// See http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
double Sound::scale(double octaveTones, double baseFrequency, double halfNotesAwayFromBase) {
	return baseFrequency * pow(pow(2, 1.0 / octaveTones), halfNotesAwayFromBase); 
}

double Sound::tone(double t, double f, double normalizedPhase) {
	return sin(2 * PI * t * f - PI / 2 + 2 * PI * normalizedPhase);
}

double Sound::freq(double t, double frequency, double normalizedPhase, double min, double max) {
	double y = sin(2 * PI * t * frequency - PI / 2 + 2 * PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

double Sound::period(double t, double period, double normalizedPhase, double min, double max) {
	double y = sin(2 * PI * t / period - PI / 2 + 2 * PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

// Apply the attack-decay-sustain-release envelope to the sample.
double Sound::envelope(double clockTime, double sample) const {
	if (clockTime < startTime) return 0;
	double dt = clockTime - startTime;
	if (dt < attack) return (dt / attack * attackDelta) * sample;
	dt -= attack;
	if (dt < decay) return (attackDelta - dt / decay * decayDelta) * sample;
	dt -= decay;
	double sustain = duration - attack - decay - release;
	if (dt < sustain) return (attackDelta - decayDelta) * sample;
	dt -= sustain;
	if (dt < release) return (attackDelta - decayDelta) * (1 - dt / release) * sample;
	return 0;
}

void Sound::writeWavFile(const string & filename) const {
	assert(startTime == 0);

	cout << "Duration: " << duration / 60 << " minutes" << endl;

	ofstream f;
	f.open(filename, ios::out | ios::binary | ios_base::trunc); 

	// Write the riff chunk ID.
	f.put('R');
	f.put('I');
	f.put('F');
	f.put('F');
    
	// Write riff chunk size.
	unsigned int numSamples = samplesPerSecond * duration;
	unsigned int bytesPerSample = sizeof(signed short);
	assert(bytesPerSample == 2);
	unsigned short numChannels = 2;
	unsigned int numSampleBytes = numSamples * bytesPerSample * numChannels;
	unsigned int riffChunkSize =  4 + 24 + 8 + numSampleBytes;
	assert(sizeof(unsigned int) == 4);
	f.write((const char *)(&riffChunkSize), 4);
    
	// Write the riff format.
	f.put('W');
	f.put('A');
	f.put('V');
	f.put('E');

	// Write the fmt chunk ID.
	f.put('f');
	f.put('m');
	f.put('t');
	f.put(' ');
    
	// Write the fmt chunk size.
	unsigned int fmtChunkSize = 16;
	f.write((const char *)(&fmtChunkSize), 4);

	// Write audio format.
	unsigned short audioFormat = 1;
	assert(sizeof(unsigned short) == 2);
	f.write((const char *)(&audioFormat), 2);

	// Write number of channels.
	f.write((const char *)(&numChannels), 2);
  
	// Write sample rate.
	f.write((const char *)(&samplesPerSecond), 4);
  
	// Write byte rate.
	unsigned int byteRate = samplesPerSecond * numChannels * bytesPerSample;
	f.write((const char *)(&byteRate), 4);

	// Write block align.
	unsigned short blockAlign = numChannels * bytesPerSample;
	f.write((const char *)(&blockAlign), 2);

	// Write bits per sample.
	unsigned short bitsPerSample = 8 * bytesPerSample;
	f.write((const char *)(&bitsPerSample), 2);

	// Write the fmt chunk ID.
	f.put('d');
	f.put('a');
	f.put('t');
	f.put('a');
    
	// Write the data chunk size.
	f.write((const char *)(&numSampleBytes), 4);
  
	for (unsigned int t = 0; t < numSamples; ++t) {
		double seconds = t / (double) samplesPerSecond;

		// Alter amplitude to ramp up at start and ramp down at end.
		signed short s = (SHRT_MAX >> 1) * envelope(seconds, sample(seconds));

		f.write(reinterpret_cast<const char *>(&s), 2);
		f.write(reinterpret_cast<const char *>(&s), 2);
	}

	f.close();
	cout << "OK" << endl;
}

