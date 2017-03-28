#include "Kronos.h"
#include "Wave1.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"

Kronos::Kronos() : Sound(0, 20 * 60) {
	double startTime = 0;
	double dur = 20 * 60 / 5;
	double overlap = 24;
	double rampDuration = 9;
	double s = 0;   // interval start time
	double d = 240; // interval duration
	waves.push_back(new Wave1( s -  0, d + 12, .2, 12)); s += 240; 
	waves.push_back(new Wave2( s - 12, d + 24, 12, 12)); s += 240;
	waves.push_back(new Wave3( s - 12, d + 24, 12, 12)); s += 240;
	waves.push_back(new Wave4( s - 12, d + 24, 12, 12)); s += 240;
	waves.push_back(new Wave5( s - 12, d +  0, 12, 12)); s += 240;
}

double Kronos::sample(double t) const {
	double s = 0;
	for (int i = 0; i < waves.size(); ++i) {
		s += waves[i]->rampedSample(t);
	}
	//s /= 2;
	return s;
}


