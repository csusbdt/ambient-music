#include "Kronos.h"

double Kronos::sample(double t) const {
	double s = 0;
	s += wave1.sample(t);
	s /= 4;
	return s;
}


