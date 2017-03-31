#include <iostream>
#include <cassert>
#include "Wave1.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"
#include "Kronos.h"
#include "SelfSimilar1.h"
#include "RandyNotes.h"

using namespace std;

int main(int argc, char * argv[]) {
	// Get sound name and duration from command line.
	if (argc != 2) {
		cout << "Usage:" << endl;
		cout << argv[0] << " sound-name" << endl;
		return 0;
	}

	string soundName(argv[1]);

	Sound * sound = 0;
	if (soundName == "wave1") sound = new Wave1();
	if (soundName == "wave2") sound = new Wave2();
	if (soundName == "wave3") sound = new Wave3();
	if (soundName == "wave4") sound = new Wave4();
	if (soundName == "wave5") sound = new Wave5();
	if (soundName == "kronos") sound = new Kronos();
	if (soundName == "ss1") sound = new SelfSimilar1();
	if (soundName == "rn") sound = new RandyNotes();
	if (sound == 0) {
		cout << "Sound name not found." << endl;
		return 0;
	}

	sound->writeWavFile(soundName + ".wav");

	cout << "Done." << endl;
}

