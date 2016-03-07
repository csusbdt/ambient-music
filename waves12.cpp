#include "main.inc"

// waves12.cpp   

void init() {
	rampUpTime = 1.0;
	rampDownTime = 1.5;
	duration = 9 * 60;
}

double sample(double t) {
	double s1 = 0;

	s1 += tone(t, 199 * 1)   * freq(t, 13)       * period(t, 8);
	s1 += tone(t, 199 * PHI) * freq(t, 13 * PHI) * period(t, 8 / PHI);
	s1 += tone(t, 199 * 2)   * freq(t, 13 / PHI) * period(t, 8 * PHI);

	double s2 = 0;

	s2 += tone(t, 200 * 1)   * freq(t, 12)       * period(t, 10);
	s2 += tone(t, 200 / PHI) * freq(t, 12 * PHI) * period(t, 10 / PHI);
	s2 += tone(t, 200 * 2)   * freq(t, 12 / PHI) * period(t, 10 * PHI);

	double s3 = 0;

	s3 += tone(t, 201 * 1)   * freq(t, 11)       * period(t, 12);
	s3 += tone(t, 201 / PHI) * freq(t, 11 * PHI) * period(t, 12 / PHI);
	s3 += tone(t, 201 * 2)   * freq(t, 11 / PHI) * period(t, 12 * PHI);

	double s4 = 0;

	s4 += tone(t, 202 * 1)   * freq(t, 10)       * period(t, 14);
	s4 += tone(t, 202 / PHI) * freq(t, 10 * PHI) * period(t, 14 / PHI);
	s4 += tone(t, 202 * 2)   * freq(t, 10 / PHI) * period(t, 14 * PHI);

	double s5 = 0;

	s5 += tone(t, 230 * 1)   * freq(t, 5)       * period(t, 8);
	s5 += tone(t, 230 * PHI) * freq(t, 5 * PHI) * period(t, 8 / PHI);
	s5 += tone(t, 230 * 2)   * freq(t, 5 / PHI) * period(t, 8 * PHI);

	double s6 = 0;

	s6 += tone(t, 270 * 1)   * freq(t, 7)       * period(t, 10);
	s6 += tone(t, 270 / PHI) * freq(t, 7 * PHI) * period(t, 10 / PHI);
	s6 += tone(t, 270 * 2)   * freq(t, 7 / PHI) * period(t, 10 * PHI);

	double s7 = 0;

	s7 += tone(t, 291 * 1)   * freq(t, 9)       * period(t, 12);
	s7 += tone(t, 291 / PHI) * freq(t, 9 * PHI) * period(t, 12 / PHI);
	s7 += tone(t, 291 * 2)   * freq(t, 9 / PHI) * period(t, 12 * PHI);

	double s8 = 0;

	s8 += tone(t, 302 * 1)   * freq(t, 11)       * period(t, 14);
	s8 += tone(t, 302 / PHI) * freq(t, 11 * PHI) * period(t, 14 / PHI);
	s8 += tone(t, 302 * 2)   * freq(t, 11 / PHI) * period(t, 14 * PHI);

	double s = 	s1 * period(t, duration, 0) + 
			s2 * period(t, duration, 1 / PHI) + 
			s3 * period(t, duration, 1 / PHI / PHI) +
			s4 * period(t, duration, 1 / PHI / PHI / PHI) +
			s5 * period(t, duration, 0) + 
			s6 * period(t, duration, 1 / PHI) + 
			s7 * period(t, duration, 1 / PHI / PHI) +
			s8 * period(t, duration, 1 / PHI / PHI / PHI);

	s /= 8;
	assert(-1 <= s && s <= 1);

	return s; 
}

