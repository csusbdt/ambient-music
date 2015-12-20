#include "main.inc"

// waves7.cpp 

void init() {
	rampUpTime = 1.0;
	rampDownTime = 1.5;
	duration = 16 * 60;
}

double sample(double t) {
	double s1 = 0;

	s1 += tone(t, 432) * freq(t, 8) * period(t, 10);
	s1 += tone(t, 433) * freq(t, 8) * period(t, 11);
	s1 += tone(t, 410) * freq(t, 5) * period(t, 19);
	s1 += tone(t, 410.5) * period(t, 21);

	double s2 = 0;

	s2 += tone(t, 100) * freq(t, 8) * period(t, 8);
	s2 += tone(t, 200) * freq(t, 6) * period(t, 12);

	double s3 = 0;

	s3 += tone(t, 480) * period(t, 24);
	s3 += tone(t, 510) * period(t, 31);

	double s = s1 * period(t, 120, 0) + s2 * period(t, 120, .33) + s3 * period(t, 120, .66);

	s /= 16;
	assert(-1 <= s && s <= 1);

	return s; 
}

