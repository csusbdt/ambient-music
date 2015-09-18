#include "main.inc"

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 6 * 12 * pow(PHI, 4);
}

double sample(double t) {
	const double F = 528;  // base tone frequency
	const double T = 7.83; // base tremolo frequency
	const double P = 12;   // base note period
	double s = 
		sin(2 * PI * t * F / pow(PHI, -2)) *
		(sin(2 * PI * t * T / pow(PHI, -2)) * .5 + .5) *  // waking 
		(sin(2 * PI * t / (P * pow(PHI, -2)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) + 3 / 3 * PI / 2), 5) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, -1)) *
		(sin(2 * PI * t * T / pow(PHI, -1)) * .5 + .5) *  // dream/waking transition
		(sin(2 * PI * t / (P * pow(PHI, -1)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) + 2 / 3 * PI / 2), 5) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 0)) *
		(sin(2 * PI * t * T / pow(PHI, 0)) * .5 + .5) *  // dreaming boundary
		(sin(2 * PI * t / (P * pow(PHI, 0)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) + 1 / 3 * PI / 2), 5) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 1)) *
		(sin(2 * PI * t * T / pow(PHI, 1)) * .5 + .5) *  // dreaming
		(sin(2 * PI * t / (P * pow(PHI, 1)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) + 0 / 3 * PI / 2), 5) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 2)) *
		(sin(2 * PI * t * T / pow(PHI, 2)) * .5 + .5) *  // deep sleep boundary
		(sin(2 * PI * t / (P * pow(PHI, 2)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) - 1 / 3 * PI / 2), 5) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 3)) *
		(sin(2 * PI * t * T / pow(PHI, 3)) * .5 + .5) *  // deep sleep
		(sin(2 * PI * t / (P * pow(PHI, 3)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) - 2 / 3 * PI / 2), 5) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 4)) *
		(sin(2 * PI * t * T / pow(PHI, 4)) * .5 + .5) *  // deep sleep
		(sin(2 * PI * t / (P * pow(PHI, 4)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) - 3 / 3 * PI / 2), 5) * .5 + .5);
	s /= 4;
	assert(-1 <= s && s <= 1);
	return s; 
}

