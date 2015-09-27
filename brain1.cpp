#include "main.inc"

// Brain wave frequencies
//   0.1 -  4 Hz  DELTA  dreamless sleep
//     4 -  8 Hz  THETA  dream sleep
//     8 - 14 Hz  ALPHA  transition between sleeping and waking states
//    14 - 30 Hz  BETA   waking state
// http://transcendentaltones.com/index.php?option=com_content&view=article&id=82&Itemid=89

const double F = 396;  // base tone frequency
//const double F = 528; 
const double T = 6;   // base tremolo frequency
const double P = 8;   // base note period

void init() {
	rampUpTime = 0.0;
	rampDownTime = 1.5;
	duration = 20 * 60;
}

double sample(double t) {
	double d = duration;
	double s = 
		sin(2 * PI * t * F / pow(PHI, 0)) *
		(sin(2 * PI * t * T / pow(PHI, 0) - PI / 2) * .5 + .5) * 
		(sin(2 * PI * t / (P * pow(PHI, 0)) - PI / 2) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 1)) *
		(sin(2 * PI * t * T / pow(PHI, 0) - PI / 4) * .5 + .5) *  
		(sin(2 * PI * t / (P * pow(PHI, 1)) - PI / 2) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 2)) *
		(sin(2 * PI * t * T / pow(PHI, 0) + PI / 4) * .5 + .5) *  
		(sin(2 * PI * t / (P * pow(PHI, 2)) - PI / 2) * .5 + .5)
		+
		sin(2 * PI * t * F / pow(PHI, 3)) *
		(sin(2 * PI * t * T / pow(PHI, 0) + PI / 2) * .5 + .5) *  
		(sin(2 * PI * t / (P * pow(PHI, 3)) - PI / 2) * .5 + .5);
	s /= 32;
	assert(-1 <= s && s <= 1);
	return s; 
}

