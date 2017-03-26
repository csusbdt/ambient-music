#include <iostream>
#include <cmath>
#include <fstream>
#include <cassert>
#include <vector>
#include <climits>
#include <map>

#include "Composition1.h"
#include "Composition2.h"
#include "Composition5.h"
#include "Kronos.h"

using namespace std;

// In this code, time is normally specified in seconds.

int main(int argc, char * argv[]) {
	map<const string, Composition *> compositions;

	compositions["wave1"] = new Composition1();
	compositions["wave2"] = new Composition2();
	compositions["wave5"] = new Composition5();
	compositions["kronos"] = new Kronos();

	// Get composition name from command line.
	if (argc != 2) {
		cout << "arguments: <composition name>" << endl; 
		return 0;
	}
	string name(argv[1]);

	// Check that composition name exists.
	if (compositions.count(name) == 0) {
		cout << "Name not found.  Choose from: ";
		map<const string, Composition *>::iterator it = compositions.begin();
		map<const string, Composition *>::iterator end = compositions.end();
		for (;it != end; ++it) cout << it->first << "  ";
		cout << endl;
		return 0;
	}

	// Get the specified composition object and write it's samples to a wav file.
	const Composition * c = compositions[name];
	c->writeWavFile(name + ".wav");

	cout << "Done." << endl;
}

