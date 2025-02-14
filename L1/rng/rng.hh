#ifndef RNG_HH
#define RNG_HH

#include <random>

struct RNG {
	std::random_device device;
	std::mt19937	  generator;
};

/**
 * @brief Inicializa un generador de números aleatorios declarado previamente
 */
void rng_init(RNG& rng);

/**
 * @brief Genera un entero al azar 'x' que cumple: x >= min && x <= max, 
 * uniformemente entre ambos límites
 * 
 * @param rng El generador de números al azar
 * @param min Valor mínimo que puede tomar `x`
 * @param max Valor máximo que puede tomar `x`
 */
int rng_generate(RNG& rng, int min, int max);

/**
 * @brief Genera un real al azar 'x' que cumple: x >= min && x <= max, 
 * uniformemente entre ambos límites
 * 
 * @param rng El generador de números al azar
 * @param min Valor mínimo que puede tomar `x`
 * @param max Valor máximo que puede tomar `x`
 */
double rng_generate(RNG& rng, double min, double max);


#endif