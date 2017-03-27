#pragma once

#include "Wave.h"

using namespace std;

class Wave4 : public Wave {
public:
	Wave4(double startTime, double duration) : Wave(startTime, duration) { 
	}

	Wave4() : Wave(0, 30) { 
	}

	virtual double sample(double t) const;

};

