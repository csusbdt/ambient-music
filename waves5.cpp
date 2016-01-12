#include "main.inc"

// waves5.cpp

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 20 * 60;
}

double sample(double t) {
	double P = 6;
	double s = 0;

	s +=	tone(t, 396) *
		freq(t, 7.83) *
		period(t, P * pow(2, 0)) *
		period(t, P * pow(1.8, 4)) *
		1;

	s +=	tone(t, 417) *
		freq(t, 14.3) *
		period(t, P * pow(2, 1)) *
		period(t, P * pow(1.8, 3)) *
		1;

	s +=	tone(t, 528) *
		freq(t, 20.8) *
		period(t, P * pow(2, 2)) *
		1;

	s +=	tone(t, 639) *
		freq(t, 27.3) *
		period(t, P * pow(2, 3)) *
		1;

	s +=	tone(t, 741) *
		freq(t, 33.8) *
		period(t, P * pow(2, 4)) *
		1;

	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

