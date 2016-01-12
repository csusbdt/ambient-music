#include "main.inc"

// waves6.cpp

double cycle(double t, double period, double normalizedPhase = 0, double min = 0, double max = 1) {
	double y = sin(2 * PI * t / period - PI / 2 + PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

void init() {
	rampUpTime = 1.0;
	rampDownTime = 1.5;
	duration = 18 * 60;
}

double sample(double t) {
	double STEPS = 20;
	double B = 432;
	double P2 = 6;

	double s1 = 0;

	s1 +=	tone(t, scale(STEPS, B, 0)) *
		freq(t, 4) *
		cycle(t, 6) *
		cycle(t, 240, 0.00) *
		1;

	s1 +=	tone(t, scale(STEPS, B, -12)) *
		freq(t, 4) *
		cycle(t, 7) *
		cycle(t, 240, 0.25) *
		1;

	s1 +=	tone(t, scale(STEPS, B, -8)) *
		freq(t, 8) *
		cycle(t, 8) *
		cycle(t, 240, 0.50) *
		1;

	s1 +=	tone(t, scale(STEPS, B, -20)) *
		freq(t, 8) *
		cycle(t, 5) *
		cycle(t, 240, 0.75) *
		1;

	double s2 = 0;

	s2 +=	tone(t, scale(STEPS, B, -16)) *
		freq(t, 12) *
		cycle(t, 9) *
		1;

	s2 +=	tone(t, scale(STEPS, B, -28)) *
		freq(t, 12) *
		cycle(t, 12) *
		1;

	s2 *=	cycle(t, 90, .5);

	double s3 = 0;

	for (int i = 0; i < 4; ++i) {
		s3 +=	tone(t, scale(12, B, i - 3)) *
			cycle(t, 10 * pow(1.2, i)) *
			cycle(t, 120, 0) *
			1;
	}

	for (int i = 0; i < 4; ++i) {
		s3 +=	tone(t, scale(12, B, i + 3)) *
			cycle(t, 10 * pow(1.2, i)) *
			cycle(t, 120, .5) *
			1;
	}


	double s = s1 + s2 + s3;
	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

