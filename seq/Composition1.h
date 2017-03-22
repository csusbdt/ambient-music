#pragma once

#include "Composition.h"

// formerly waves1.cpp

class Composition1 : public Composition {
public:
	Composition1();
	double sample(double t) const;
};

