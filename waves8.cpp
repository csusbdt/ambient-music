#include "main.inc"

// waves8.cpp   ********************* UNFINISHED **********************

// See http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
double scale(double octaveTones, double baseFrequency, double halfNotesAwayFromBase) {
	return baseFrequency * pow(pow(2, 1.0 / octaveTones), halfNotesAwayFromBase); 
}

double tone(double t, double f) {
	return sin(2 * PI * t * f);
}

double freq(double t, double frequency, double normalizedPhase = 0, double min = 0, double max = 1) {
	double y = sin(2 * PI * t * frequency - PI / 2 + PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

double period(double t, double period, double normalizedPhase = 0, double min = 0, double max = 1) {
	double y = sin(2 * PI * t / period - PI / 2 + PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

void init() {
	rampUpTime = 1.0;
	rampDownTime = 1.5;
	duration = 12 * 60;
}

double sample(double t) {
	double F = 16;
	double P = 6;

	double BIG_P = duration;

	double s1 = 0;

	s1 += tone(t, 180 * 1)   * freq(t, 16)       * period(t, 8);
	s1 += tone(t, 180 * PHI) * freq(t, 16 * PHI) * period(t, 8 / PHI);
	s1 += tone(t, 180 * 2)   * freq(t, 16 / PHI) * period(t, 8 * PHI);

	double s2 = 0;

	s2 += tone(t, 220 * 1)   * freq(t, 12)       * period(t, 11);
	s2 += tone(t, 220 / PHI) * freq(t, 12 * PHI) * period(t, 11 / PHI);
	s2 += tone(t, 220 * 2)   * freq(t, 12 / PHI) * period(t, 11 * PHI);

	double s = s1 * period(t, BIG_P, 0) + s2 * period(t, BIG_P, 1 / PHI);

	s /= 8;
	assert(-1 <= s && s <= 1);

	return s; 
}

