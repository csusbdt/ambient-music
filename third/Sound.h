#pragma once

#include <string>

using namespace std;

class Sound {
public:
	static const double PI;
	static const double PHI;
	static const double E;
	static const unsigned int samplesPerSecond;

	static double scale(double octaveTones, double baseFrequency, double halfNotesAwayFromBase);
	static double tone(double t, double f, double normalizedPhase = 0);
	static double freq(double t, double frequency, double normalizedPhase = 0, double min = 0, double max = 1);
	static double period(double t, double period, double normalizedPhase = 0, double min = 0, double max = 1);

	Sound(double startTime = 0, double duration = 30, double rampUpTime = .01, double rampDownTime = .01)
	: startTime(startTime), duration(duration), rampUpTime(rampUpTime), rampDownTime(rampDownTime) {
	}

	void writeWavFile(const string & filename) const;

	virtual double sample(double seconds) const = 0;
	double rampedSample(double t) const;

protected:
	double startTime;
	double duration;

private:
	double rampUpTime;
	double rampDownTime;

};

