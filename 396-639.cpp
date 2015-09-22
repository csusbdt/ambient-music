#include "main.inc"

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 5 * 12 * 12 * PHI;
}

double sample(double t) {
	const double maxAmplitude = 1.0 / 2;
	double s = 
		sin(2 * PI * t * 396) *
		(sin(2 * PI * t * 7.83       - PI / 2) * .5 + .5) *
		(sin(2 * PI * t / 12         - PI / 2) * .5 + .5) 
		+
		sin(2 * PI * t * 639) *
		(sin(2 * PI * t * 14.3       - PI / 2) * .5 + .5) *
		(sin(2 * PI * t / (12 * PHI) - PI / 2) * .5 + .5);
	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

