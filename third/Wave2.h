#pragma once

#include "Wave.h"

using namespace std;

class Wave2 : public Wave {
public:
	Wave2() : Wave(30) { 
	}

	virtual double sample(double t) const;
};
