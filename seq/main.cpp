#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <climits>
#include <cmath>
#include "Sound.h"

using namespace std;

struct Composition : public Sound {
	Composition() : Sound() {}

	virtual void init() {
		startTime = 0.0;
		duration = 12 * 12 * PHI;
		rampUpTime = 0.0;
		rampDownTime = 1.5;
	}

	virtual double sample(double t) {
		double s1 = 0;
		s1 += tone(t, 180 * 1) * freq(t, 16) * period(t, 8);
		return s1;
	}
};

static unsigned int samplesPerSecond = 48000;

int main(int argc, char * argv[]) {
	// Get filename from command line.
	if (argc != 2) {
		cout << "arguments: <filename>" << endl; 
		return 0;
	}
	const char * filename = argv[1];

	Composition composition;
	composition.init();

	double duration = 
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

	// Check for degenerate case (duration too short).
	assert(duration > composition.rampUpTime + composition.rampDownTime); 
  
	for (unsigned int t = 0; t < numSamples; ++t) {
		double time = t / (double) samplesPerSecond;

		// Alter amplitude to ramp up at start and ramp down at end.
		double rampMultiplier = 1.0;
		if (time < composition.rampUpTime) {
			rampMultiplier = 1 - (composition.rampUpTime - time) / composition.rampUpTime;
		} else if (time > duration - composition.rampDownTime) {
			rampMultiplier = (duration - time) / composition.rampDownTime;
		}
        
		signed short s = (signed short) (rampMultiplier * (SHRT_MAX >> 1) * composition.sample(time));

		f.write(reinterpret_cast<const char *>(&s), 2);
		f.write(reinterpret_cast<const char *>(&s), 2);
	}

	f.close();
	cout << "OK" << endl;
}

