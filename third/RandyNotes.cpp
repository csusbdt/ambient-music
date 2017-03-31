#include "RandyNotes.h"
#include <cassert>
#include <cmath>

#include <iostream>

RandyNotes::RandyNotes() : Sound(0, 120, 0, 0) {
	Envelope e(120);
	Note n(120, e);
cout << e.startTime << " ; " << e.duration <<  " ; " << e.decay << endl;
	//Note n(120, Envelope(120));
	notes.push_back(n);
}

double RandyNotes::sample(double t) const {
	t -= startTime;

	double s = 0;
	for (auto n : notes) s += n.sample(t);

	//s /= 8;
	assert(-1 <= s && s <= 1);
	return s; 
}

