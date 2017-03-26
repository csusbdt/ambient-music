#include "Kronos.h"
#include <cassert>
#include <iostream>

static const double DURATION = 30;
static const double START_TIME = 0;
static const double RAMP_UP_TIME = 1.0;
static const double RAMP_DOWN_TIME = 1.5;

Kronos::Kronos() : Composition(DURATION, START_TIME, RAMP_UP_TIME, RAMP_DOWN_TIME) {
	composition1 = new Composition1(DURATION,  0.0, 1.0, 1.5);
	composition2 = new Composition2(DURATION, 15.0, 1.0, 1.5);
	composition5 = new Composition5(DURATION, 30.0, 1.0, 1.5);
	duration = 50;
};

double Kronos::sample(double t) const {
	double s = 0;

	if (t >=  0 && t < 30) s += composition1->sample(t -  0);
	if (t >= 10 && t < 40) s += composition2->sample(t - 10);
	if (t >= 20 && t < 50) s += composition5->sample(t - 20);

	s /= 2;
	assert(-1 <= s && s <= 1);

	return s; 
}

