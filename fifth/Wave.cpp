#include "Wave.h"
#include <cmath>

double Wave::wave(double t, double f, double waver, double p, double h) {
	return tone(t, f) * freq(t, waver) * period(t, p, h);
}

