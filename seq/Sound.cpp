#include <iostream>
#include <cmath>
#include "Sound.h"

using namespace std;

const double Sound::PI = 3.141592653589793238462;
const double Sound::PHI = 1.61803398875;
const double Sound::E = 2.718281828459;

double Sound::tone(double t, double f, double normalizedPhase) {
	return sin(2 * PI * t * f - PI / 2 + 2 * PI * normalizedPhase);
}

double Sound::freq(double t, double frequency, double normalizedPhase, double min, double max) {
	double y = sin(2 * PI * t * frequency - PI / 2 + 2 * PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

double Sound::period(double t, double period, double normalizedPhase, double min, double max) {
	double y = sin(2 * PI * t / period - PI / 2 + 2 * PI * normalizedPhase) * .5 + .5;
	return min + (max - min) * y;
}

