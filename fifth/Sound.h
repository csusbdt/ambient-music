#pragma once

#include <cassert>
#include <string>
#include <cstdio>
#include "Envelope.h"

using namespace std;

class Sound {
public:
	static const double PI;
	static const double PHI;
	static const double E;
	static const unsigned int samplesPerSecond;

	static double scale(double octaveTones, double baseFrequency, double halfNotesAwayFromBase);
	static double tone(double t, double f, double normalizedPhase = 0);
	static double freq(double t, double frequency, double normalizedPhase = 0, double min = 0, double max = 1);
	static double period(double t, double period, double normalizedPhase = 0, double min = 0, double max = 1);

	Sound(	double startTime   =  0    , 
		double duration    = 30    , 
		double attack      =  0.01 , 
		double decay       =  0.02 ,
		double release     =  0.04 ,
		double attackDelta =  1.00 ,
		double decayDelta  =  0.10
	) :
		startTime   (startTime)    ,
		duration    (duration)     ,
		attack      (attack)       , 
		decay       (decay)        , 
		release     (release)      ,
		attackDelta (attackDelta)  ,
		decayDelta  (decayDelta)  
	{
		assert(duration > attack + decay + release); // Check for degenerate case (duration too short).
	}

	void writeSamples(FILE * file) const;

	virtual double sample(double seconds) const = 0;

	double startTime;
	double duration;
	double attack;
	double decay;
	double release;
	double attackDelta; // normalized
	double decayDelta;  // normalized

protected:
	double envelope(double clockTime, double sample) const;
};

