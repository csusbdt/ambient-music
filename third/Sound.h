#pragma once

#include <string>

using namespace std;

class Sound {
public:
	static const double PI;
	static const double PHI;
	static const double E;
	static const unsigned int samplesPerSecond;

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

