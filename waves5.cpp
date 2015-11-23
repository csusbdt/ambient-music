#include "main.inc"

// waves5.cpp

// See http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
double freq(double octaveTones, double baseFrequency, double halfNotesAwayFromBase) {
	return baseFrequency * pow(pow(2, 1.0 / octaveTones), halfNotesAwayFromBase); 
}

double tone(double t, double f) {
	return sin(2 * PI * t * f);
}

double cycle(double t, double period, double min = 0, double max = 1, double normalizedPhase = 0) {
	double y = sin(2 * PI * t / period - PI / 2 + PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 20 * 60;
}

double sample(double t) {
	double P = 6;
	double s = 0;

	s +=	tone(t, 396) *
		cycle(t, 1 / 7.83) *
		cycle(t, P * pow(2, 0)) *
		cycle(t, P * pow(1.8, 4)) *
		1;

	s +=	tone(t, 417) *
		cycle(t, 1 / 14.3) *
		cycle(t, P * pow(2, 1)) *
		cycle(t, P * pow(1.8, 3)) *
		1;

	s +=	tone(t, 528) *
		cycle(t, 1 / 20.8) *
		cycle(t, P * pow(2, 2)) *
		1;

	s +=	tone(t, 639) *
		cycle(t, 1 / 27.3) *
		cycle(t, P * pow(2, 3)) *
		1;

	s +=	tone(t, 741) *
		cycle(t, 1 / 33.8) *
		cycle(t, P * pow(2, 4)) *
		1;

	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

