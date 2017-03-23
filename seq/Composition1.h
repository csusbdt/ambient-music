#pragma once

#include "Composition.h"

// formerly waves1.cpp

class Composition1 : public Composition {
public:
	Composition1();

	Composition1(double duration, double startTime, double rampUpTime, double rampDownTime);

	double sample(double t) const;
};

