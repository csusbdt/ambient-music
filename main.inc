/***********************************************************************
 *
 * Music generation code created by David Turner
 * csusbdt@gmail.com
 * https://github.com/csusbdt/ambient-music/
 *
 * This file should be included in a file that defines the init and
 * sample functions.  Example:
 *
 ***********************************************************************

	#include "main.inc"

	void init() {
		rampUpTime = 0.0;
		rampDownTime = 1.5;
		duration = 12 * 12 * PHI;
	}

	double sample(double t) {
		const double maxAmplitude = SHRT_MAX >> 3;
		return 	maxAmplitude * 
			sin(2 * PI * t * 396) *
			(sin(2 * PI * t * 7.83       - PI / 2) / 2 + .5) *
			(sin(2 * PI * t / 12         - PI / 2) / 2 + .5) 
			+
			maxAmplitude *
			sin(2 * PI * t * 639) *
			(sin(2 * PI * t * 14.3       - PI / 2) / 2 + .5) *
			(sin(2 * PI * t / (12 * PHI) - PI / 2) / 2 + .5);
	}

 ***********************************************************************/
#include <iostream>
#include <cmath>
#include <fstream>
#include <cassert>
#include <vector>
#include <climits>

void init();
double sample(double t);

using namespace std;

const double PI = 3.141592653589793238462;
const double PHI = 1.61803398875;
const double E = 2.718281828459;

// The following should be set in the init function.
// In this code, time is normally specified in seconds.
unsigned int samplesPerSecond 	= 48000;
double rampUpTime 		= 0.0; 
double rampDownTime 		= 0.0;
double duration 		= 3 * 60; // duration of the music 

int main(int argc, char * argv[]) {
	// Get filename from command line.
	if (argc != 2) {
		cout << "arguments: <filename>" << endl; 
		return 0;
	}
	const char * filename = argv[1];

	init();

	cout << "Duration: " << duration / 60 << " minutes" << endl;

	ofstream f;
	f.open(filename, ios::out | ios::binary | ios_base::trunc); 

	// Write the riff chunk ID.
	f.put('R');
	f.put('I');
	f.put('F');
	f.put('F');
    
	// Write riff chunk size.
	unsigned int numSamples = samplesPerSecond * duration;
	unsigned int bytesPerSample = sizeof(signed short);
	assert(bytesPerSample == 2);
	unsigned short numChannels = 2;
	unsigned int numSampleBytes = numSamples * bytesPerSample * numChannels;
	unsigned int riffChunkSize =  4 + 24 + 8 + numSampleBytes;
	assert(sizeof(unsigned int) == 4);
	f.write((const char *)(&riffChunkSize), 4);
    
	// Write the riff format.
	f.put('W');
	f.put('A');
	f.put('V');
	f.put('E');

	// Write the fmt chunk ID.
	f.put('f');
	f.put('m');
	f.put('t');
	f.put(' ');
    
	// Write the fmt chunk size.
	unsigned int fmtChunkSize = 16;
	f.write((const char *)(&fmtChunkSize), 4);

	// Write audio format.
	unsigned short audioFormat = 1;
	assert(sizeof(unsigned short) == 2);
	f.write((const char *)(&audioFormat), 2);

	// Write number of channels.
	f.write((const char *)(&numChannels), 2);
  
	// Write sample rate.
	f.write((const char *)(&samplesPerSecond), 4);
  
	// Write byte rate.
	unsigned int byteRate = samplesPerSecond * numChannels * bytesPerSample;
	f.write((const char *)(&byteRate), 4);

	// Write block align.
	unsigned short blockAlign = numChannels * bytesPerSample;
	f.write((const char *)(&blockAlign), 2);

	// Write bits per sample.
	unsigned short bitsPerSample = 8 * bytesPerSample;
	f.write((const char *)(&bitsPerSample), 2);

	// Write the fmt chunk ID.
	f.put('d');
	f.put('a');
	f.put('t');
	f.put('a');
    
	// Write the data chunk size.
	f.write((const char *)(&numSampleBytes), 4);

	//unsigned int numSamples = samplesPerSecond * duration;
	assert(duration > rampUpTime + rampDownTime); // Check for degenerate case (duration too short).
  
	for (unsigned int t = 0; t < numSamples; ++t) {
		double time = t / (double) samplesPerSecond;

		// Alter amplitude to ramp up at start and ramp down at end.
		double rampMultiplier = 1.0;
		if (time < rampUpTime) {
			rampMultiplier = 1 - (rampUpTime - time) / rampUpTime;
		} else if (time > duration - rampDownTime) {
			rampMultiplier = (duration - time) / rampDownTime;
		}
        
		signed short s = (signed short) (rampMultiplier * (SHRT_MAX >> 1) * sample(time));

		f.write(reinterpret_cast<const char *>(&s), 2);
		f.write(reinterpret_cast<const char *>(&s), 2);
	}


	f.close();
	cout << "OK" << endl;
}

