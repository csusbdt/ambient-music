#pragma once

#include <vector>
#include "Wave.h"

using namespace std;

class Kronos : public Sound {
public:
	Kronos();
	virtual double sample(double t) const;

private:
	vector<Wave *> waves;
};

