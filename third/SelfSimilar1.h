#pragma once

#include "Wave.h"

using namespace std;

class SelfSimilar1 : public Wave {
public:
	SelfSimilar1(double startTime, double duration) : Wave(startTime, duration) { 
	}

	SelfSimilar1() : Wave(0, 120) { 
	}

	virtual double sample(double t) const;
};

