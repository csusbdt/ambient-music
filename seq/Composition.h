#pragma once

class Composition {
public:
//	static const double PI;
//	static const double PHI;
//	static const double E;

	double startTime;
	double duration;
	double rampUpTime;
	double rampDownTime;

	virtual void init() = 0;
	virtual double sample(double t) = 0;
	double getMaxTime() { return startTime + duration; }

//	static double tone(double t, double f, double normalizedPhase = 0);
//	static double freq(double t, double frequency, double normalizedPhase = 0, double min = 0, double max = 1);
//	static double period(double t, double period, double normalizedPhase = 0, double min = 0, double max = 1);

	Composition() : startTime(0), duration(0), rampUpTime(0), rampDownTime(0) {}
};

