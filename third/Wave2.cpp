#include "Wave2.h"
#include <cassert>

double Wave2::sample(double t) const {
	double s1 = 0;
	s1 += tone(t, 188 * 1)   * freq(t, 16)       * period(t, 8);
	s1 += tone(t, 188 * PHI) * freq(t, 16 * PHI) * period(t, 8 / PHI);
	s1 += tone(t, 188 * 2)   * freq(t, 16 / PHI) * period(t, 8 * PHI);

	double s2 = 0;
	s2 += tone(t, 200 * 1)   * freq(t, 12)       * period(t, 10);
	s2 += tone(t, 200 / PHI) * freq(t, 12 * PHI) * period(t, 10 / PHI);
	s2 += tone(t, 200 * 2)   * freq(t, 12 / PHI) * period(t, 10 * PHI);

	double s3 = 0;
	s3 += tone(t, 204 * 1)   * freq(t, 9)       * period(t, 12);
	s3 += tone(t, 204 / PHI) * freq(t, 9 * PHI) * period(t, 12 / PHI);
	s3 += tone(t, 204 * 2)   * freq(t, 9 / PHI) * period(t, 12 * PHI);

	double s4 = 0;
	s4 += tone(t, 207 * 1)   * freq(t, 6)       * period(t, 14);
	s4 += tone(t, 207 / PHI) * freq(t, 6 * PHI) * period(t, 14 / PHI);
	s4 += tone(t, 207 * 2)   * freq(t, 6 / PHI) * period(t, 14 * PHI);

	double s = 	s1 * period(t, duration / 3, 0) + 
			s2 * period(t, duration / 3, 1 / PHI) + 
			s3 * period(t, duration / 3, 1 / PHI / PHI) +
			s4 * period(t, duration / 3, 1 / PHI / PHI / PHI);

	s /= 8;
	assert(-1 <= s && s <= 1);

	return s; 
}

