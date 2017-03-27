#pragma once

#include "Sound.h"

using namespace std;

class Wave : public Sound {
public:
	static double scale(double octaveTones, double baseFrequency, double halfNotesAwayFromBase);
	static double tone(double t, double f, double normalizedPhase = 0);
	static double freq(double t, double frequency, double normalizedPhase = 0, double min = 0, double max = 1);
	static double period(double t, double period, double normalizedPhase = 0, double min = 0, double max = 1);
	static double wave(double t, double f, double waver, double p, double h = 0);

	Wave(double startTime, double duration = 0, double rampUpTime = .1, double rampDownTime = .1) 
	: Sound(startTime, duration, rampUpTime, rampDownTime) {
	}
};

