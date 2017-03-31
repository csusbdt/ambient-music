#include "Note.h"
#include <cassert>
#include <cmath>

double Note::sample(double clockTime) const {
	double t = clockTime - startTime;
	if (t < 0) return 0;
	if (t > duration) return 0;

	double s = 0;
	s += tone(t, frequency) * freq(t, 8);

	s = envelope.filter(t, s);

	s /= 4;
	assert(-1 <= s && s <= 1);
	return s; 
}

