#pragma once

#include "Wave.h"

using namespace std;

class Wave3 : public Wave {
public:
	Wave3() : Wave(30) { 
	}

	virtual double sample(double t) const;
};

