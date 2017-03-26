#pragma once

#include "Composition.h"
#include "Composition1.h"
#include "Composition2.h"
#include "Composition5.h"

class Kronos : public Composition {
public:
	Kronos();
	double sample(double t) const;

private:
	Composition1 * composition1;
	Composition2 * composition2;
	Composition5 * composition5;
};

