#pragma once

#include "Sound.h"
#include "Envelope.h"

#include <iostream>

using namespace std;

class Note : public Sound {
public:
	Note(double frequency, Envelope e) 
	: Sound(e.startTime, e.duration, 0, 0), frequency(frequency), envelope(e) {
//cout << e.startTime << " ; " << e.duration <<  " ; " << frequency << endl;
	}

	virtual double sample(double clockTime) const;

	double frequency;
	Envelope envelope;
};

