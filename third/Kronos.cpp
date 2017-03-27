#include "Kronos.h"
#include "Wave1.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"

Kronos::Kronos() : Sound(0, 120) {
	waves.push_back(new Wave1( 0, 120));
	waves.push_back(new Wave2(20, 100));
/*
	waves.push_back(new Wave3(40,  80));
	waves.push_back(new Wave4(60,  60));
	waves.push_back(new Wave5(80,  40));
*/
}

double Kronos::sample(double t) const {
	double s = 0;
	for (int i = 0; i < waves.size(); ++i) {
		s += waves[i]->rampedSample(t);
	}
	s /= 8;
	return s;
}


