#pragma once

#include "Wave.h"

using namespace std;

class Wave3 : public Wave {
public:
	Wave3(	double startTime = 0, 
		double duration = 30, 
		double rampUpTime = .01, 
		double rampDownTime = .01) 
	: Wave(startTime, duration, rampUpTime, rampDownTime) {
	}

	virtual double sample(double t) const;
};

