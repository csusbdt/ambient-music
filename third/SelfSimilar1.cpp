#include "SelfSimilar1.h"
#include <cassert>
#include <cmath>

double SelfSimilar1::sample(double t) const {
	t -= startTime;

	double s = 0;
	for (int i = 0; i < 10; ++i) {
		s += tone(t, 88 + i * 12) * freq(t, 8) * period(t, 4 + i, (i - 110) / 10);
	}

	s /= 8;
	assert(-1 <= s && s <= 1);
	return s; 
}

