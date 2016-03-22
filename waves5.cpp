#include "main.inc"

// waves5.cpp

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 2 * 60;
}

double sample(double t) {
	double P = 6;
	double s = 0;

	s +=	tone(t, scale(12, 434,  0)) * freq(t,  8.00) * period(t,  6);
	s +=	tone(t, scale(12, 434,  2)) * freq(t,  9.00) * period(t,  9);
	s +=	tone(t, scale(12, 434,  4)) * freq(t, 11.00) * period(t, 11);
//	s +=	tone(t, scale(12, 434,  6)) * freq(t,  7.00) * period(t, 11);
//	s +=	tone(t, scale(12, 434,  7)) * freq(t,  8.00) * period(t, 12);
//	s +=	tone(t, scale(12, 434,  9)) * freq(t,  9.00) * period(t, 13);
//	s +=	tone(t, scale(12, 434, 11)) * freq(t, 10.00) * period(t, 14);
//	s +=	tone(t, scale(12, 434, 12)) * freq(t, 11.00) * period(t, 15);

	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

