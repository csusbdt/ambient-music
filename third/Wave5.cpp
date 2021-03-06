#include "Wave5.h"
#include <cassert>
#include <cmath>

double Wave5::sample(double clockTime) const {
	if (clockTime < startTime) return 0;
	if (clockTime > startTime + duration) return 0;

	double t = startTime - clockTime;

	double s0 = 0;
	int I0 = 6;
	double F0 = 100;
	double W0 = 12;
	double w0 = 6.0 / I0; 
	double P0 = 10;
	double p0 = pow(20.0, 1.0 / I0);
	double H0 = 1;
	double h0 = 1.0 / I0;
	for (int i = 0; i < I0; ++i) {
		double f = scale(I0, F0, i * 2);
		s0 += wave(t, f, W0 - i * w0, P0 + pow(p0, i), i * h0);
	}

	double s1 = 0;
	int I1 = 5;
	double F1 = F0;
	double W1 = 8;
	double w1 = 2.0 / I1; 
	double P1 = 20;
	double p1 = pow(30.0, 1.0 / I1);
	double H1 = 1;
	double h1 = 1.0 / I1;
	for (int i = 0; i < I1; ++i) {
		double f = scale(I1, F1, i * 2);
		s1 += wave(t, f, W1 - i * w1, P1 + pow(p1, i), i * h1);
	}

	double s2 = 0;
	s2 += wave(t, scale(I0, F0, I0 + 1), 5, duration * 4, 0.33);

	double s = 	s0 * period(t, duration * 2, 0.50) * period(t, duration * 1.50, 0.50) + 
			s1 * period(t, duration * 2, 0.00) +
			s2;

	s /= 8;
	assert(-1 <= s && s <= 1);
	return envelope(clockTime, s);
}

