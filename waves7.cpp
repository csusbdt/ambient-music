#include "main.inc"

// waves7.cpp

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

double wave(double t, double note, double per, double phase = 0) {
	return tone(t, note) * period(t, per, phase);
}

double tremolo(double t, double note, double trem, double per, double phase = 0) {
	return tone(t, note) * freq(t, trem) * period(t, per, phase);
}

void init() {
	rampUpTime = 1.0;
	rampDownTime = 1.5;
	duration = 16 * 60;
}

double sample(double t) {
	double s1 = 0;

	s1 += tone(t, 432) * freq(t, 8) * period(t, 10);
	s1 += tone(t, 433) * freq(t, 8) * period(t, 11);
	s1 += tone(t, 410) * freq(t, 5) * period(t, 19);
	s1 += tone(t, 410.5) * period(t, 21);

	double s2 = 0;

	s2 += tone(t, 100) * freq(t, 8) * period(t, 8);
	s2 += tone(t, 200) * freq(t, 6) * period(t, 12);

	double s3 = 0;

	s3 += tone(t, 480) * period(t, 24);
	s3 += tone(t, 510) * period(t, 31);

	double s = s1 * period(t, 120, 0) + s2 * period(t, 120, .33) + s3 * period(t, 120, .66);

	s /= 16;
	assert(-1 <= s && s <= 1);

	return s; 
}

