#include "main.inc"

// Change

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 5 * 60;
}

double sample(double t) {
	const double maxAmplitude = 1.0 / 2 / 2;
	double s = 
		maxAmplitude * 
		sin(2 * PI * t * 417) *
		(sin(2 * PI * t * 7.83       - PI / 2) * .5 + .5) *
		(sin(2 * PI * t / (12 * PHI) - PI / 2) * .5 + .5) 
		+
		maxAmplitude *
		sin(2 * PI * t * 741) *
		(sin(2 * PI * t * 14.3       - PI / 2) * .5 + .5) *
		(sin(2 * PI * t / 12         - PI / 2) * .5 + .5);
	assert(-1 <= s && s <= 1);
	return s; 
}

