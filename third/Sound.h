#pragma once

#include <string>

using namespace std;

class Sound {
public:
	static const double PI;
	static const double PHI;
	static const double E;
	static const unsigned int samplesPerSecond;

	Sound(double duration, double startTime = 0, double rampUpTime = .01, double rampDownTime = .01)
	: duration(duration), startTime(startTime), rampUpTime(rampUpTime), rampDownTime(rampDownTime) {
	}

	void writeWavFile(const string & filename = "out.wav") const;

protected:
	double duration;
	double startTime;

private:
	double rampUpTime;
	double rampDownTime;

	double rampedSample(double t) const;
	virtual double sample(double t) const = 0;
};

