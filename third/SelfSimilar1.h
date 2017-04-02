#pragma once

#include "Sound.h"

using namespace std;

class SelfSimilar1 : public Sound {
public:
	SelfSimilar1(double startTime = 0, double duration = 20 * 60, double rampUpTime = .02, double rampDownTime = 10)
	: Sound() {
		this->startTime = startTime;
		this->duration = duration;
		attack = rampUpTime;
		decay = 0;
		release = rampDownTime;
		attackDelta = 1.0;
		decayDelta =  0;
	}

	virtual double sample(double t) const;
};

