#include <string>
#include "Sound.h"

using namespace std;

struct WavFile {
	WavFile(const string & filename) : sound(0), filename(filename) {}
	void addSound(const Sound & sound);
	void generate();

	const Sound * sound;
	string filename;

	// In this code, time is normally specified in seconds.
	static const unsigned int samplesPerSecond;
};

