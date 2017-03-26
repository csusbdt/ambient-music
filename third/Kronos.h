#pragma once

#include <string>
#include "Wave1.h"

using namespace std;

class Kronos : public Sound {
public:
	Kronos() : Sound(30) {}
	virtual double sample(double t) const;

private:
	Wave1 wave1;
};

