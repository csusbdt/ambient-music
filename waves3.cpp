#include "main.inc"

// waves2.cpp

// See http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
double freq(double baseFrequency, int halfNotesAwayFromBase) {
	//return baseFrequency * pow(pow(2, 1.0 / 12), halfNotesAwayFromBase);  // western 12-tone scale
	//return baseFrequency * pow(pow(2, 1.0 / 5), halfNotesAwayFromBase); // 5-tone scale
	//return baseFrequency * pow(pow(2, 1.0 / 6), halfNotesAwayFromBase); // 6-tone scale
	//return baseFrequency * pow(pow(2, 1.0 / 7), halfNotesAwayFromBase); 
	return baseFrequency * pow(pow(2, 1.0 / 9), halfNotesAwayFromBase); 
}

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 16 * 60;
}

double sample(double t) {
	const double P = 9;
	const double B = 1.3;
	const double D = 0.85;
	const double F = 320;
	double s = 
		pow(D, 0) *
		sin(2 * PI * t * freq(F, -8)) *
		sin(2 * PI * t * 4.0) *
		(sin(2 * PI * t / (P * pow(B, 8)) - PI / 2) * .50 + .50)
		+
		pow(D, 1) *
		sin(2 * PI * t * freq(F, -6)) *
		sin(2 * PI * t * 4.5) *
		(sin(2 * PI * t / (P * pow(B, 7)) - PI / 2) * .50 + .50) 
		+
		pow(D, 2) *
		sin(2 * PI * t * freq(F, -4)) *
		sin(2 * PI * t * 5.0) *
		(sin(2 * PI * t / (P * pow(B, 6)) - PI / 2) * .50 + .50) 
		+
		pow(D, 3) *
		sin(2 * PI * t * freq(F, -2)) *
		sin(2 * PI * t * 5.5) *
		(sin(2 * PI * t / (P * pow(B, 5)) - PI / 2) * .50 + .50) 
		+
		pow(D, 4) *
		sin(2 * PI * t * freq(F, 0)) *
		sin(2 * PI * t * 6.0) *
		(sin(2 * PI * t / (P * pow(B, 4)) - PI / 2) * .50 + .50) 
		+
		pow(D, 5) *
		sin(2 * PI * t * freq(F, 2)) *
		sin(2 * PI * t * 7.83) *
		(sin(2 * PI * t / (P * pow(B, 3)) - PI / 2) * .50 + .50) 
		+
		pow(D, 6) *
		sin(2 * PI * t * freq(F, 4)) *
		(sin(2 * PI * t / (P * pow(B, 2)) - PI / 2) * .50 + .50) 
		+
		pow(D, 7) *
		sin(2 * PI * t * freq(F, 6)) *
		(sin(2 * PI * t / (P * pow(B, 1)) - PI / 2) * .50 + .50) 
		+
		pow(D, 8) *
		sin(2 * PI * t * freq(F, 8)) *
		(sin(2 * PI * t / (P * pow(B, 0)) - PI / 2) * .50 + .50);
		s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

