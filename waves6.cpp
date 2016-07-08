#include "main.inc"

// waves6.cpp

void init() {
	rampUpTime = 1.0;
	rampDownTime = 5.0;
	duration = 1 * 60;
}

double wave(double t, double f, double waver, double p = 0, double h = 0) {
	if (p == 0) {
		return tone(t, f) * freq(t, waver);
	} else {
		return tone(t, f) * freq(t, waver) * period(t, p, h);
	}
}

double sample(double t) {
	double s = 0;

	double F = 528; // base frequency

	double s1 = wave(t, F, 5, 10, 0);

//	s += s1 * period(t, duration, 0.00);
//	s += s2 * period(t, duration, 0.50);
	//s += s3 * period(t, duration, 0.00);

	s += s1;

	s /= 8;
	assert(-1 <= s && s <= 1);
	return s; 
}

