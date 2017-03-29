#pragma once

#include "Sound.h"

using namespace std;

class Wave : public Sound {
public:
	static double wave(double t, double f, double waver, double p, double h = 0);

	Wave(double startTime, double duration = 0, double rampUpTime = .1, double rampDownTime = .1) 
	: Sound(startTime, duration, rampUpTime, rampDownTime) {
	}
};

