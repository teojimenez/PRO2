#include <iostream>
#include <random>
using namespace std;

#include "rng.hh"

void rng_init(RNG& rng) {
	rng.generator = mt19937(rng.device());
}

int rng_generate(RNG& rng, int min, int max) {
	uniform_int_distribution<int> distribution(min, max);
	return distribution(rng.generator);
}

double rng_generate(RNG& rng, double min, double max) {
    uniform_real_distribution<double> distribution(min, max);
    return distribution(rng.generator);
}