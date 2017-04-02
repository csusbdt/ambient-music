#include "SelfSimilar1.h"
#include <cassert>
#include <cmath>

double SelfSimilar1::sample(double clockTime) const {
	if (clockTime < startTime) return 0;
	if (clockTime > startTime + duration) return 0;

	double t = clockTime - startTime;

	double s = 0;
	for (int i = 0; i < 12; ++i) {
		s += tone(t, 88 + i * 4) * freq(t, 8) * period(t, 4 + i, (i - 110) / 10);
	}

	s /= 4;
	assert(-1 <= s && s <= 1);
	return envelope(clockTime, s); 
}

