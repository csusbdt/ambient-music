#pragma once

#include "Wave.h"

using namespace std;

class Wave1 : public Wave {
public:
	Wave1() : Wave(30) { 
	}

	virtual double sample(double t) const;
};

