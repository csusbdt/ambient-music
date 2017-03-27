#include "Kronos.h"
#include "Wave1.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"
#include "SelfSimilar1.h"

Kronos::Kronos() : Sound(0, 20 * 60) {
	double startTime = 0;
	double timeInc = 20 * 60 / 6;
	double overlap = 12;
	waves.push_back(new Wave1(startTime++ * timeInc, timeInc + overlap));
	waves.push_back(new Wave2(startTime++ * timeInc, timeInc + overlap));
	waves.push_back(new Wave3(startTime++ * timeInc, timeInc + overlap));
	waves.push_back(new Wave4(startTime++ * timeInc, timeInc + overlap));
	waves.push_back(new Wave5(startTime++ * timeInc, timeInc + overlap));
	waves.push_back(new SelfSimilar1(startTime++ * timeInc, timeInc));
}

double Kronos::sample(double t) const {
	double s = 0;
	for (int i = 0; i < waves.size(); ++i) {
		s += waves[i]->rampedSample(t);
	}
	//s /= 2;
	return s;
}


