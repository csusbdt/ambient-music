#pragma once

#include "Composition.h"

// formerly waves5.cpp

class Composition5 : public Composition {
public:
	Composition5();
	Composition5(double duration, double startTime, double rampUpTime, double rampDownTime);

	double sample(double t) const;

private:
	double wave(double t, double f, double waver, double p, double h = 0) const;
};

