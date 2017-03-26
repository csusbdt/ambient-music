#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>
#include "Sound.h"

using namespace std;

const double Sound::PI = 3.141592653589793238462;
const double Sound::PHI = 1.61803398875;
const double Sound::E = 2.718281828459;

static const unsigned int samplesPerSecond = 48000;

void Sound::writeWavFile(const string & filename) const {
	assert(startTime == 0);

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


