#include <iostream>
#include <cassert>
#include <cstdio>
#include "Kronos.h"

using namespace std;

int main(int argc, char * argv[]) {
	FILE * result = freopen(0, "wb", stdout);
	if (result == 0) {
		perror("Error reopening stdout");
		exit(1);
	}

	Sound * sound = new Kronos();
	sound->writeSamples(stdout);
}

