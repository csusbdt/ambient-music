#include "main.inc"

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 3 * 9 * 12 * PHI * PHI;
}

double sample(double t) {
	const double maxAmplitude = 1.0 / 2 / 2;
	double s = 
		maxAmplitude * 
		sin(2 * PI * t * 285) *
		(sin(2 * PI * t * 7.83             - PI / 2) / 2 + .5) *
		(sin(2 * PI * t / (12 * PHI * PHI) - PI / 2) * .45 + .55) 
		+
		maxAmplitude *
		sin(2 * PI * t * 528) *
		(sin(2 * PI * t * 14.3             - PI / 2) / 2 + .5) *
		(sin(2 * PI * t / (12 * PHI)       - PI / 2) / 2 + .5) *
		(sin(2 * PI * t / (12 * PHI * PHI) + PI / 2) / 2 + .5) 
		+
		maxAmplitude * .5 *
		sin(2 * PI * t * 852) *
		(sin(2 * PI * t * 20.8             - PI / 2) / 2 + .5) *
		(sin(2 * PI * t / 12               - PI / 2) / 2 + .5) *
		(sin(2 * PI * t / (12 * PHI * PHI) - PI / 2) / 2 + .5);
	assert(-1 <= s && s <= 1);
	return s; 
}

