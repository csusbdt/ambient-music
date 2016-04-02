#include "main.inc"

// waves6.cpp

void init() {
	rampUpTime = 1.0;
	rampDownTime = 5.0;
	duration = 4 * 60;
}

double wave(double t, double f, double waver, double p = 0, double h = 0) {
	if (p == 0) {
		return tone(t, f) * freq(t, waver);
	} else {
		return tone(t, f) * freq(t, waver) * period(t, p, h);
	}
}

double sample(double t) {

	double s0 = wave(t, 120, 8);
	for (int i = 0; i < 3; ++i) {
		s0 *= period(t, 20 * pow(1.5, i));
	}
	double s1 = wave(t, 120 * PHI, 6);
	for (int i = 0; i < 3; ++i) {
		s1 *= period(t, 20 * pow(1.5, i), .5);
	}
	double s2 = 0;

	double s = s0 + s1;
/*
	double s = 	s0 * period(t, duration * 2, 0.50) * period(t, duration * 1.50, 0.50) + 
			s1 * period(t, duration * 2, 0.00) +
			s2;
*/

	s /= 8;
	assert(-1 <= s && s <= 1);
	return s; 
}

