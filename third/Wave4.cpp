#include "Wave4.h"
#include <cassert>
#include <cmath>

double Wave4::wave(double t, double f, double waver, double p, double h) {
	return tone(t, f) * freq(t, waver) * period(t, p, h);
}

double Wave4::sample(double t) const {
	double s0 = 0;
	double F = 100;
	double f = 1.2;
	double W = 14;
	double w = 0.95;
	double P = 10;
	double p = 1.4;
	double H = 1;
	double h = .95;
	int I = 10;
	for (int i = 0; i < I; ++i) {
		s0 += wave(t, F * pow(f, i), W * pow(w, i), P * pow(p, i), H * pow(h, i));
	}

	double s1 = 0;
	double F1 = 120;
	double f1 = 1.2;
	double W1 = 8;
	double w1 = 0.80;
	double P1 = 14;
	double p1 = 1.1;
	double H1 = 1;
	double h1 = .95;
	int I1 = 6;
	for (int i = 0; i < I1; ++i) {
		s1 += wave(t, F1 * pow(f1, i), W1 * pow(w1, i), P1 * pow(p1, i), H1 * pow(h1, i));
	}

	double s2 = 0;

	double F2 = 140;
	double f2 = 1.025;
	double W2 = 10;
	double w2 = 0.70;
	double P2 = 20;
	double p2 = 1.0;
	double H2 = 1;
	double h2 = 0.85;
	int I2 = 5;
	for (int i = 0; i < I2; ++i) {
		s2 += wave(t, F2 * pow(f2, i), W2 * pow(w2, i), P1 * pow(p2, i), H2 * pow(h2, i));
	}

	double s = 	s0 * period(t, duration * 2, 0.5) * period(t, duration * 1.5, 0.5) + 
			s1 * period(t, duration * 2, 0.0) +
			s2 * period(t, duration / 2, 0.0);

	s /= 8;
	assert(-1 <= s && s <= 1);
	return s; 
}

