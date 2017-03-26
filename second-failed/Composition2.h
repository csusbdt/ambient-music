#pragma once

#include "Composition.h"

// formerly waves2.cpp

class Composition2 : public Composition {
public:
	Composition2();

	Composition2(double duration, double startTime, double rampUpTime, double rampDownTime);

	double sample(double t) const;
};

