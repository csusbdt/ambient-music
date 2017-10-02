#pragma once

#include <cstdlib>

int randomInt(int a, int b) {
        return a + rand() % (b - a + 1);
}

double randomDouble(double a = 0, double b = 1) {
        return a + (b - a) * rand() / (double) RAND_MAX;
}

float randomFloat(float a = 0, float b = 1) {
        return (float) (a + (b - a)) * rand() / (double) RAND_MAX;
}

double randomBool(double p = 0.5) {
        return rand() / (double) RAND_MAX < p;
}

double normal(double mean = 0, double std = 1) {
        double x = 0;
        for (unsigned int i = 0; i < 12; ++i) {
                x += randomDouble();
        }
        x = x - 6;
        return mean + std * x;
}

