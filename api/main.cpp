#include <iostream>
#include <cassert>
#include <cstdio>
#include "Wave1.h"

using namespace std;

int main(int argc, char * argv[]) {
	FILE * result = freopen(0, "wb", stdout);
	if (result == 0) {
		perror("Error reopening stdout");
		exit(1);
	}

	double durationInSeconds = 30;
	Wave1 wave1(0, durationInSeconds, .2, 4); 
	unsigned int samplesPerSecond = 48000;
	unsigned int durationInSamples = samplesPerSecond * durationInSeconds;
	for (int i = 0; i < durationInSamples; ++i) {
		double seconds = i / (double) samplesPerSecond;
		wave1.writeSample(stdout, seconds);
	}
}

