#include "Note.h"
#include <cassert>
#include <cmath>

double Note::sample(double clockTime) const {
	double dt = clockTime - startTime;
	if (dt < 0) return 0;
	if (dt > duration) return 0;

	double s = 0;
	//s += tone(dt, frequency) * freq(dt, 8);
	s += tone(dt, frequency);
	s += tone(dt, frequency * 2) / 2.0;
	s += tone(dt, frequency * 4) / 4.0;
	s += tone(dt, frequency * 8) / 8.0;
	s += tone(dt, frequency * 16) / 16.0;

	s /= 4;
	assert(-1 <= s && s <= 1);
	return envelope(clockTime, s);
}

