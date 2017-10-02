#include "Kronos.h"
#include "Wave1.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"

Kronos::Kronos() : Sound() {
	double intervalDuration = 240; 

	startTime = 0;
	duration = 20 * intervalDuration;
	attack = .5;
	decay = 0;
	release = 12;
	attackDelta = 1.0;
	decayDelta =  0;

	double s = 0;   // interval start time
	double d = intervalDuration;
	// overlap: 12s
	waves.push_back(new Wave1(s -  0, d + 12, .2, 12)); s += d; 
	waves.push_back(new Wave2(s - 12, d + 24, 12, 12)); s += d;
	waves.push_back(new Wave3(s - 12, d + 24, 12, 12)); s += d;
	waves.push_back(new Wave4(s - 12, d + 24, 12, 12)); s += d;
	waves.push_back(new Wave5(s - 12, d + 24, 12, 12)); s += d;

	// overlap: 30s
	waves.push_back(new Wave1(s - 12, d + 42, 12, 30)); s += d; 
	waves.push_back(new Wave2(s - 30, d + 60, 30, 30)); s += d;
	waves.push_back(new Wave3(s - 30, d + 60, 30, 30)); s += d;
	waves.push_back(new Wave4(s - 30, d + 60, 30, 30)); s += d;
	waves.push_back(new Wave5(s - 30, d + 60, 30, 30)); s += d;

	// overlap: 60s
	waves.push_back(new Wave1(s - 30, d +  90, 30, 60)); s += d; 
	waves.push_back(new Wave2(s - 60, d + 120, 60, 60)); s += d;
	waves.push_back(new Wave3(s - 60, d + 120, 60, 60)); s += d;
	waves.push_back(new Wave4(s - 60, d + 120, 60, 60)); s += d;
	waves.push_back(new Wave5(s - 60, d + 120, 60, 60)); s += d;

	// overlap: 120s
	waves.push_back(new Wave1(s -  60, d + 180,  60, 120)); s += d; 
	waves.push_back(new Wave2(s - 120, d + 240, 120, 120)); s += d;
	waves.push_back(new Wave3(s - 120, d + 240, 120, 120)); s += d;
	waves.push_back(new Wave4(s - 120, d + 240, 120, 120)); s += d;
	waves.push_back(new Wave5(s - 120, d + 120, 120,  12)); s += d;
}

double Kronos::sample(double clockTime) const {
	double s = 0;
	for (int i = 0; i < waves.size(); ++i) {
		s += waves[i]->sample(clockTime);
	}
	s /= 2;
	return envelope(clockTime, s);
}


