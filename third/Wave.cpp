#include "Wave.h"
#include <cmath>

// See http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
double Wave::scale(double octaveTones, double baseFrequency, double halfNotesAwayFromBase) {
	return baseFrequency * pow(pow(2, 1.0 / octaveTones), halfNotesAwayFromBase); 
}

double Wave::tone(double t, double f, double normalizedPhase) {
	return sin(2 * PI * t * f - PI / 2 + 2 * PI * normalizedPhase);
}

double Wave::freq(double t, double frequency, double normalizedPhase, double min, double max) {
	double y = sin(2 * PI * t * frequency - PI / 2 + 2 * PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

double Wave::period(double t, double period, double normalizedPhase, double min, double max) {
	double y = sin(2 * PI * t / period - PI / 2 + 2 * PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}


