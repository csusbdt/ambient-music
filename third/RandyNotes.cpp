#include "RandyNotes.h"
#include <cassert>
#include <cmath>

RandyNotes::RandyNotes() : Sound() {
	// Initialize Sound variables.
	startTime = 0;
	duration = 5 * 240.0 / 20;
	attack = .5;
	decay = 0;
	release = 12;
	attackDelta = 1.0;
	decayDelta =  0;

	// Create notes.
	Note n;
	notes.push_back(n);
}

double RandyNotes::sample(double clockTime) const {
	double dt = clockTime - startTime;
	double s = 0;
	for (auto n : notes) s += n.sample(dt);

	s /= 2;
	assert(-1 <= s && s <= 1);
	return envelope(clockTime, s); 
}

