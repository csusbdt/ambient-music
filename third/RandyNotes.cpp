#include "RandyNotes.h"
#include <cassert>
#include <cmath>

RandyNotes::RandyNotes() : Sound() {
	startTime = 0;
	duration = 60;
	attack = .01;
	decay = 0;
	release = 1;
	attackDelta = 1.0;
	decayDelta =  0;

	for (int i = 0; i < 30; i += 2) {
		Note n(90 + 2 * i);
		n.startTime = i;
		n.duration = 2.1;
		n.attack = .02;
		n.decay = .03;
		n.release = .2;
		n.attackDelta = 1;
		n.decayDelta = .2;
		notes.push_back(n);
	}
}

double RandyNotes::sample(double clockTime) const {
	double dt = clockTime - startTime;
	double s = 0;
	for (auto n : notes) s += n.sample(dt);

	s /= 2;
	assert(-1 <= s && s <= 1);
	return envelope(clockTime, s); 
}

