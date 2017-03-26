#include <iostream>
#include <cassert>
#include <map>
#include "Wave1.h"
//#include "Waves2.h"
#include "Kronos.h"

using namespace std;

int main(int argc, char * argv[]) {
	map<const string, Sound *> sounds;

	sounds["wave1"] = new Wave1();
//	sounds["wave2"] = new Wave2();
	sounds["kronos"] = new Kronos();

	// Get sound name and duration from command line.
	double duration = 0;
	if (argc == 1) {
		cout << "Usage:" << endl;
		cout << argv[0] << " sound-name [duration]" << endl;
		return 0;
	} else if (argc == 2) {
		// do nothing
	} else if (argc == 3) {
		duration = stoi(argv[2]);
	}
	string soundName(argv[1]);

	// Check that sound exists.
	if (sounds.count(soundName) == 0) {
		cout << "Sound name not found." << endl;
		cout << "Choose from: ";
		map<const string, Sound *>::iterator it = sounds.begin();
		map<const string, Sound *>::iterator end = sounds.end();
		for (;it != end; ++it) {
			cout << it->first << "  ";
		}
		cout << endl;
		return 0;
	}

	// Get the specified track object and write it's samples to a wav file.
	const Sound * sound = sounds[soundName];
	sound->writeWavFile(soundName + ".wav");

	cout << "Done." << endl;
}

