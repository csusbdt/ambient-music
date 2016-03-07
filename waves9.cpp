#include "main.inc"

// waves9.cpp   

void init() {
	rampUpTime = 1.0;
	rampDownTime = 1.5;
	duration = 24 * 60;
}

double sample(double t) {
	double s1 = 0;

	s1 += tone(t, 180 * 1)   * freq(t, 16)       * period(t, 8);
	s1 += tone(t, 180 * PHI) * freq(t, 16 * PHI) * period(t, 8 / PHI);
	s1 += tone(t, 180 * 2)   * freq(t, 16 / PHI) * period(t, 8 * PHI);

	double s2 = 0;

	s2 += tone(t, 220 * 1)   * freq(t, 12)       * period(t, 11);
	s2 += tone(t, 220 / PHI) * freq(t, 12 * PHI) * period(t, 11 / PHI);
	s2 += tone(t, 220 * 2)   * freq(t, 12 / PHI) * period(t, 11 * PHI);

	double s3 = 0;

	s3 += tone(t, 260 * 1)   * freq(t, 9)       * period(t, 15);
	s3 += tone(t, 260 / PHI) * freq(t, 9 * PHI) * period(t, 15 / PHI);
	s3 += tone(t, 260 * 2)   * freq(t, 9 / PHI) * period(t, 15 * PHI);

	//double s = s1 * period(t, duration, 0) + s2 * period(t, duration, 1 / 3) + s3 * period(t, duration, 2 / 3);
	double s = s1 * period(t, duration, 0) + s2 * period(t, duration, 1 / PHI) + s3 * period(t, duration, 1 / PHI / PHI);

	s /= 8;
	assert(-1 <= s && s <= 1);

	return s; 
}

