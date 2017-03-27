#pragma once

#include "Wave.h"

using namespace std;

class Wave1 : public Wave {
public:
	Wave1(double startTime, double duration) : Wave(startTime, duration) { 
	}

	Wave1() : Wave(0, 30) { 
	}

	virtual double sample(double t) const;
};

