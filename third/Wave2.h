#pragma once

#include "Wave.h"

using namespace std;

class Wave2 : public Wave {
public:
	Wave2(double startTime, double duration) : Wave(startTime, duration) { 
	}

	Wave2() : Wave(0, 30) { 
	}

	virtual double sample(double t) const;
};

