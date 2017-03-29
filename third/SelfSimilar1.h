#pragma once

#include "Sound.h"

using namespace std;

class SelfSimilar1 : public Sound {
public:
	SelfSimilar1(double startTime = 0, double duration = 20 * 60, double rampUpTime = .02, double rampDownTime = 10)
	: Sound(startTime, duration, rampUpTime, rampDownTime) {
	}

	virtual double sample(double t) const;
};

