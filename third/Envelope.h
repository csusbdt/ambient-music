#pragma once

using namespace std;

class Envelope {
public:
	Envelope(
			double duration    = 1.00 , 
			double attack      = 0.02 , 
			double decay       = 0.04 , 
			double release     = 0.10 , 
			double attackDelta = 1.00 , 
			double decayDelta  = 0.10
	) :
			duration    (duration)    ,
			attack      (attack)      , 
			decay       (decay)       , 
			release     (release)     ,
			attackDelta (attackDelta) ,
			decayDelta  (decayDelta)  
	{ }

	double filter(double dt, double sample) const {
		if (dt < 0) return 0;
		if (dt < attack) return (dt / attack * attackDelta) * sample;
		dt -= attack;
		if (dt < decay) return (attackDelta - dt / decay * decayDelta) * sample;
		dt -= decay;
		double sustain = duration - attack - decay - release;
		if (dt < sustain) return (attackDelta - decayDelta) * sample;
		dt -= sustain;
		if (dt < release) return (attackDelta - decayDelta) * (1 - dt / release) * sample;
		return 0;
	}

	double startTime;
	double duration; 
	double attack;
	double decay;
	double release;
	double attackDelta; // normalized
	double decayDelta;  // normalized
};

