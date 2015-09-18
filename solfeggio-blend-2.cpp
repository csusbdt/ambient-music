#include "main.inc"

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 12 * 12 * pow(PHI, 4);
}

double sample(double t) {
	const double maxAmplitude = 1.0 / 2 / 2;
	const double P = 12;
	double s = 
		maxAmplitude *
		sin(2 * PI * t * 396) *
		(sin(2 * PI * t * 33.3              - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 4)) - PI / 2) * .50 + .50)
		+
		maxAmplitude *
		sin(2 * PI * t * 417) *
		(sin(2 * PI * t * 27.3              - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 3)) - PI / 2) * .50 + .50)
		+
		maxAmplitude *
		sin(2 * PI * t * 528) *
		(sin(2 * PI * t * 20.8              - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 2)) - PI / 2) * .50 + .50)
		+
		maxAmplitude *
		sin(2 * PI * t * 639) *
		(sin(2 * PI * t * 14.3              - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 1)) - PI / 2) * .50 + .50)
		+
		maxAmplitude *
		sin(2 * PI * t * 741) *
		(sin(2 * PI * t * 7.83              - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 0)) - PI / 2) * .50 + .50);
	assert(-1 <= s && s <= 1);
	return s; 
}

