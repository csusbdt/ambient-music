#pragma once

#include <string>

using namespace std;

class Sound {
public:
	static const double PI;
	static const double PHI;
	static const double E;

	Sound(double duration, double startTime = 0, double rampUpTime = .01, double rampDownTime = .01)
	: duration(duration), startTime(startTime), rampUpTime(rampUpTime), rampDownTime(rampDownTime) {
	}

	void writeWavFile(const string & filename = "out.wav") const;

protected:
	double duration;

private:
	double startTime;
	double rampUpTime;
	double rampDownTime;

	virtual double sample(double t) const = 0;
};

