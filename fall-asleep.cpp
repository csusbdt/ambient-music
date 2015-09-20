#include "main.inc"

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 6 * 12 * pow(PHI, 4);
}

double ramp(double t, double t0, double a0, double t1, double a1) {
	if (t < t0) return a0;
	if (t > t1) return a1;
	return (t - t0) / (t1 - t0) * a0 + (t1 - t) / (t1 - t0) * a1;
}

// (-tanh(slope / center * (t - center)) * .5 + .5) / (-tanh(slope / center * (t - center)) * .5 + .5)
// (-tanh(slope / center * (t - center + left_shift)) * .5 + .5) / (-tanh(slope / center * (t - center + left_shift)) * .5 + .5)

double sample(double t) {
	const double F = 528;  // base tone frequency
	const double T = 7.83; // base tremolo frequency
	const double P = 12;   // base note period
	double d = duration;
	double s = 
/*
		sin(2 * PI * t * F / pow(PHI, -2)) *
		(sin(2 * PI * t * T / pow(PHI, -2)) * .5 + .5) *  // waking 
		(sin(2 * PI * t / (P * pow(PHI, -2)) - PI / 2) * .5 + .5) *
		(pow(sin(2 * PI * t / (duration * 2) + 3 / 3 * PI / 2), 13) * .5 + .5)
		+
*/
		sin(2 * PI * t * F / pow(PHI, -1)) *
		(sin(2 * PI * t * T / pow(PHI, -1)) * .5 + .5) *  // dream/waking transition
		(sin(2 * PI * t / (P * pow(PHI, -1)) - PI / 2) * .5 + .5) *
		(-tanh(2 / (.5 * d) * (t - .5 * d + .5 * .5 * d)) * .5 + .5) /
		(-tanh(2 / (.5 * d) * (0 - .5 * d + .5 * .5 * d)) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 0)) *
		(sin(2 * PI * t * T / pow(PHI, 0)) * .5 + .5) *  // dreaming boundary
		(sin(2 * PI * t / (P * pow(PHI, 0)) - PI / 2) * .5 + .5) *
		(-tanh(2 / (.5 * d) * (t - .5 * d + .25 * .5 * d)) * .5 + .5) /
		(-tanh(2 / (.5 * d) * (0 - .5 * d + .25 * .5 * d)) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 1)) *
		(sin(2 * PI * t * T / pow(PHI, 1)) * .5 + .5) *  // dreaming
		(sin(2 * PI * t / (P * pow(PHI, 1)) - PI / 2) * .5 + .5) *
		(sin(2 * PI * t / (d / 2) + PI) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 2)) *
		(sin(2 * PI * t * T / pow(PHI, 2)) * .5 + .5) *  // deep sleep boundary
		(sin(2 * PI * t / (P * pow(PHI, 2)) - PI / 2) * .5 + .5) *
		(tanh(2 / (.5 * d) * (t - .5 * d)) * .5 + .5) /
		(tanh(2 / (.5 * d) * (d - .5 * d)) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 3)) *
		(sin(2 * PI * t * T / pow(PHI, 3)) * .5 + .5) *  // deep sleep
		(sin(2 * PI * t / (P * pow(PHI, 3)) - PI / 2) * .5 + .5) *
		(tanh(2 / (.5 * d) * (t - .5 * d - .25 * .5 * d)) * .5 + .5) /
		(tanh(2 / (.5 * d) * (d - .5 * d - .25 * .5 * d)) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 4)) *
		(sin(2 * PI * t * T / pow(PHI, 4)) * .5 + .5) *  // deep sleep
		(sin(2 * PI * t / (P * pow(PHI, 4)) - PI / 2) * .5 + .5) *
		(tanh(2 / (.5 * d) * (t - .5 * d - .5 * .5 * d)) * .5 + .5) /
		(tanh(2 / (.5 * d) * (d - .5 * d - .5 * .5 * d)) * .5 + .5);
	s /= 4;
	assert(-1 <= s && s <= 1);
	return s; 
}

