#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <vector>

#include "color_convert.h"
#include "my_random.h"

using namespace std;

int seed = 2;

const int OBJS = 48;
const int ROWS = 1400;
const int COLS = 1400;

struct Object {
	double row;
	double col;
	double radius;
	double hue;

	Object(int row, int col, int radius, int hue) :
		row(row), col(col), radius(radius), hue(hue) {}

	Object() {
		row    = randomDouble( 50, ROWS - 50);
		col    = randomDouble( 10, COLS - 10);
		radius = randomDouble( 50, 600);
		hue    = randomDouble(  0, 359);
	}

	double weight(int r, int c) {
		double d = sqrt((r - row) * (r - row) + (c - col) * (c - col));
		if (d > radius) 
			return 0;
		else 
			return 1 - d / radius;
	}
};

int main(int argc, char * argv[]) {
	srand(seed);

	ofstream f;
	f.open("out.rgb", ios::out | ios::binary | ios_base::trunc); 

	vector<Object> objs(OBJS);

	for (unsigned int i = 0; i < ROWS; ++i) {
		for (unsigned int j = 0; j < COLS; ++j) {
			double totalWeight = 0; 
			for (int k = 0; k < objs.size(); ++k) {
				totalWeight += objs[k].weight(i, j);
			}
			float hue;
			if (totalWeight == 0 || (totalWeight < 1.0 && randomBool(1 - totalWeight))) {
				hue = randomInt(0, 360);
			} else {
				for (int k = 0; k < objs.size(); ++k) {
					if (randomBool(objs[k].weight(i, j) / totalWeight)) {
						hue = objs[k].hue;
						break;
					}
					totalWeight -= objs[k].weight(i, j);
				}
			}

			float fr;
			float fg;
			float fb;

			HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);

			unsigned char r = floatToChar(fr);
			unsigned char g = floatToChar(fg);
			unsigned char b = floatToChar(fb);
			f.write((char *)&r, 1);
			f.write((char *)&g, 1);
			f.write((char *)&b, 1);
		}
	}
    
	f.close();
	cout << "OK" << endl;
}

