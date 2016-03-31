#include "main.inc"

// waves4.cpp

void init() {
	rampUpTime = 0.5;
	rampDownTime = 1.5;
	duration = 1 * 60;
}

double wave(double t, double f, double waver, double p, double h = 0) {
	double s = 0;
	s += tone(t, f) * freq(t, waver) * period(t, p, h);
	s += tone(t, f * PHI) * freq(t, waver * PHI) * period(t, p / 2, h);
	return s;
}

double sample(double t) {
	double s = 0;

	s += tone(t, 140      ) * freq(t, 6) * period(t, 10, 0.00);
	s += tone(t, 140 * PHI) * freq(t, 6) * period(t, 20, 0.00);

//	s += wave(t, 140, 6, 30, 0.25);
//	s += wave(t, 143, 6, 30, 0.25);
//	s += wave(t, 160, 9, 30, 0.00);

//	s += wave(t, 155, 5, 90, 0.25);
//	s += wave(t, 185, 5, 90, 0.00);

//	s += wave(t, 200, 0.001, 170, 0.25);
//	s += wave(t, 222, 0.002, 170, 0.00);

	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

