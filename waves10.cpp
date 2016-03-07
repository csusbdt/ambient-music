#include "main.inc"

// waves10.cpp   

void init() {
	rampUpTime = 1.0;
	rampDownTime = 1.5;
	duration = 9 * 60;
	duration = 27 * 60;
}

double sample(double t) {
	double s1 = 0;

	s1 += tone(t, 180 * 1)   * freq(t, 16)       * period(t, 8);
	s1 += tone(t, 180 * PHI) * freq(t, 16 * PHI) * period(t, 8 / PHI);
	s1 += tone(t, 180 * 2)   * freq(t, 16 / PHI) * period(t, 8 * PHI);

	double s2 = 0;

	s2 += tone(t, 200 * 1)   * freq(t, 12)       * period(t, 10);
	s2 += tone(t, 200 / PHI) * freq(t, 12 * PHI) * period(t, 10 / PHI);
	s2 += tone(t, 200 * 2)   * freq(t, 12 / PHI) * period(t, 10 * PHI);

	double s3 = 0;

	s3 += tone(t, 240 * 1)   * freq(t, 9)       * period(t, 12);
	s3 += tone(t, 240 / PHI) * freq(t, 9 * PHI) * period(t, 12 / PHI);
	s3 += tone(t, 240 * 2)   * freq(t, 9 / PHI) * period(t, 12 * PHI);

	double s4 = 0;

	s4 += tone(t, 260 * 1)   * freq(t, 6)       * period(t, 14);
	s4 += tone(t, 260 / PHI) * freq(t, 6 * PHI) * period(t, 14 / PHI);
	s4 += tone(t, 260 * 2)   * freq(t, 6 / PHI) * period(t, 14 * PHI);

	double s = 	s1 * period(t, duration, 0) + 
			s2 * period(t, duration, 1 / PHI) + 
			s3 * period(t, duration, 1 / PHI / PHI) +
			s4 * period(t, duration, 1 / PHI / PHI / PHI);

	s /= 8;
	assert(-1 <= s && s <= 1);

	return s; 
}

