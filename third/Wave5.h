#pragma once

#include "Wave.h"

using namespace std;

class Wave5 : public Wave {
public:
	Wave5(double startTime, double duration) : Wave(startTime, duration) { 
	}

	Wave5() : Wave(0, 30) { 
	}

	virtual double sample(double t) const;
};

