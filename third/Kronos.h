#pragma once

#include <string>
#include "Wave1.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"

using namespace std;

class Kronos : public Sound {
public:
	Kronos() : Sound(30) {}
	virtual double sample(double t) const;

private:
	Wave1 wave1;
	Wave2 wave2;
	Wave3 wave3;
	Wave4 wave4;
	Wave5 wave5;
};

