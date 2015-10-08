#include "main.inc"

// Waves

// UNDER CONSTRUCTION.  Replace Solfeggio scale with other scale.

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 9.39 * 60;
	duration = 20 * 60;
}

double sample(double t) {
	const double P = 9;
	const double B = 1.3;
	const double D = 0.95;
	double s = 
		pow(D, 0) *
		sin(2 * PI * t * 174) *
		(sin(2 * PI * t / (P * pow(B, 8)) - PI / 2) * .50 + .50)
		+
		pow(D, 1) *
		sin(2 * PI * t * 285) *
		(sin(2 * PI * t / (P * pow(B, 7)) - PI / 2) * .50 + .50) 
		+
		pow(D, 2) *
		sin(2 * PI * t * 396) *
		(sin(2 * PI * t / (P * pow(B, 6)) - PI / 2) * .50 + .50) 
		+
		pow(D, 3) *
		sin(2 * PI * t * 417) *
		(sin(2 * PI * t / (P * pow(B, 5)) - PI / 2) * .50 + .50) 
		+
		pow(D, 4) *
		sin(2 * PI * t * 528) *
		(sin(2 * PI * t / (P * pow(B, 4)) - PI / 2) * .50 + .50) 
		+
		pow(D, 5) *
		sin(2 * PI * t * 639) *
		(sin(2 * PI * t / (P * pow(B, 3)) - PI / 2) * .50 + .50) 
		+
		pow(D, 6) *
		sin(2 * PI * t * 741) *
		(sin(2 * PI * t / (P * pow(B, 2)) - PI / 2) * .50 + .50) 
		+
		pow(D, 7) *
		sin(2 * PI * t * 852) *
		(sin(2 * PI * t / (P * pow(B, 1)) - PI / 2) * .50 + .50) 
		+
		pow(D, 8) *
		sin(2 * PI * t * 964) *
		(sin(2 * PI * t / (P * pow(B, 0)) - PI / 2) * .50 + .50) *
		(sin(2 * PI * t / (duration * 2)  + PI / 2) * .50 + .50);
		s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

