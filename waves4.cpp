#include "main.inc"

// waves4.cpp

void init() {
	rampUpTime = 0.5;
	rampDownTime = 1.5;
	duration = 28 * 60;
}

double wave(double t, double f, double waver, double p, double h = 0) {
	return tone(t, f) * freq(t, waver) * period(t, p, h);
}

double sample(double t) {

	double s0 = 0;
	double F = 100;
	double f = 1.2;
	double W = 14;
	double w = 0.98;
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
	double w1 = 0.95;
	double P1 = 14;
	double p1 = 1.1;
	double H1 = 1;
	double h1 = .95;
	int I1 = 6;
	for (int i = 0; i < I; ++i) {
		s0 += wave(t, F * pow(f, i), W * pow(w, i), P * pow(p, i), H * pow(h, i));
	}

	double s = s0 * period(t, duration * 2, .5) + s1 * period(t, duration * 2, 0);

	s /= 16;
	assert(-1 <= s && s <= 1);
	return s; 
}

