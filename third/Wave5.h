#pragma once

#include "Wave.h"

using namespace std;

class Wave5 : public Wave {
public:
	Wave5() : Wave(30) { 
	}

	virtual double sample(double t) const;
};

