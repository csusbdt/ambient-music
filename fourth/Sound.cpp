#include <iostream>
#include <cmath>
#include <cassert>
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

void Sound::writeSamples(FILE * file) const {
	assert(startTime == 0);
	long numSamples = samplesPerSecond * duration;
	for (unsigned int t = 0; t < numSamples; ++t) {
		double seconds = t / (double) samplesPerSecond;
		signed short s = (SHRT_MAX >> 1) * envelope(seconds, sample(seconds));
		fwrite(reinterpret_cast<unsigned char *>(&s), 1, 2, file);
	}
}

