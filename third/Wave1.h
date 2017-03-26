#pragma once

#include "Wave.h"

using namespace std;

class Wave1 : public Wave {
public:
	Wave1() : Wave(30) { 
	}

	//Wave1(double startTime, double duration, double rampUpTime = .01, double rampDownTime = .01) 
	//: Wave(startTime, duration, rampUpTime, rampDownTime) {
	//}

	virtual double sample(double t) const;
};

