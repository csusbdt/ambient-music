#pragma once

#include <string>
#include "Constants.h"

using namespace std;

class Sequence {
public:
	static double scale(double octaveTones, double baseFrequency, double halfNotesAwayFromBase);
	static double tone(double t, double f, double normalizedPhase = 0);
	static double freq(double t, double frequency, double normalizedPhase = 0, double min = 0, double max = 1);
	static double period(double t, double period, double normalizedPhase = 0, double min = 0, double max = 1);

	virtual double sample(double t) const = 0;

	//double getMaxTime() { return startTime + duration; }
	//double getDuration() { return duration; }
	//double getRampUpTime() { return rampUpTime; }
	//double getRampDownTime() { return rampDownTime; }

protected:
	Sequence(double duration, double startTime, double rampUpTime, double rampDownTime)
	: duration(duration), startTime(startTime), rampUpTime(rampUpTime), rampDownTime(rampDownTime) {}

	double duration;
	double startTime;
	double rampUpTime;
	double rampDownTime;
};

