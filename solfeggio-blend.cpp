#include "main.inc"

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 2 * 9.39 * 60;
}

double sample(double t) {
	const double maxAmplitude = 1.0 / 2 / 2 / 2;
	const double P = 12;
	const double B = 7.83;
	const double C = 1.1;
	const double D = 0.9;
	double s = 
		maxAmplitude * pow(D, 0) *
		sin(2 * PI * t * 174) *
		(sin(2 * PI * t * B * pow(C, 0)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 8)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 1) *
		sin(2 * PI * t * 285) *
		(sin(2 * PI * t * B * pow(C, 1)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 7)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 2) *
		sin(2 * PI * t * 396) *
		(sin(2 * PI * t * B * pow(C, 2)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 6)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 3) *
		sin(2 * PI * t * 417) *
		(sin(2 * PI * t * B * pow(C, 3)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 5)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 4) *
		sin(2 * PI * t * 528) *
		(sin(2 * PI * t * B * pow(C, 4)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 4)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 5) *
		sin(2 * PI * t * 639) *
		(sin(2 * PI * t * B * pow(C, 5)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 3)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 6) *
		sin(2 * PI * t * 741) *
		(sin(2 * PI * t * B * pow(C, 6)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 2)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 7) *
		sin(2 * PI * t * 852) *
		(sin(2 * PI * t * B * pow(C, 7)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 1)) - PI / 2) * .50 + .50)
		+
		maxAmplitude * pow(D, 8) *
		sin(2 * PI * t * 964) *
		(sin(2 * PI * t * B * pow(C, 8)     - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (P * pow(PHI, 0)) - PI / 2) * .50 + .50);
	assert(-1 <= s && s <= 1);
	return s; 
}


