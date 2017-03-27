#pragma once

#include "Wave.h"

using namespace std;

class Wave3 : public Wave {
public:
	Wave3(double startTime, double duration) : Wave(startTime, duration) { 
	}

	Wave3() : Wave(0, 30) { 
	}

	virtual double sample(double t) const;
};

