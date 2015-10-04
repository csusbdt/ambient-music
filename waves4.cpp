#include "main.inc"

// waves4.cpp

// See http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
double freq(double octaveTones, double baseFrequency, double halfNotesAwayFromBase) {
	return baseFrequency * pow(pow(2, 1.0 / octaveTones), halfNotesAwayFromBase); 
}

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 12 * 60;
}

double sample(double t) {
	const double P = 2;
	const double B = 1.5;
	const double F = 120;
	double tones = 9; // + 1 * sin(2 * PI * t / 60);
	//double f = F + sin(2 * PI * t / 30) * .5;
	double f = F + sin(2 * PI * t * .2) * .0;
	assert( 0 <= f && f <= 2 * F);
	double s = 0;
	for (int i = 0; i < 14; ++i) {
		s+=	sin(2 * PI * t * freq(tones, f, pow(1.3, i))) *
			(sin(2 * PI * t * 7.83) * .5 + .5) *
			(sin(2 * PI * t / (P * pow(B, i)) - PI / 2) * .5 + .5);
	}
	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

