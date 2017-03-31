#pragma once

#include <vector>
#include "Sound.h"
#include "Note.h"

using namespace std;

class RandyNotes : public Sound {
public:
	RandyNotes();

	virtual double sample(double clockTime) const;

	vector<Note> notes;
};

