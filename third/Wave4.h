#pragma once

#include "Wave.h"

using namespace std;

class Wave4 : public Wave {
public:
	Wave4() : Wave(30) { 
	}

	virtual double sample(double t) const;

};

