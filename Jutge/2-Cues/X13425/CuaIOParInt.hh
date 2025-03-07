#ifndef CUA_IO_PARINT_HH
#define CUA_IO_PARINT_HH

#include <queue>
#include <iostream>
#include "ParInt.hh"

/**
 * @brief Llegeix parells d'enters i els afegeix a la cua
 *
 * @param c cua de parells enters buida.
 * @pre canal d'entrada hi han parells d'enters acabat en 0 0
 * @post cua amb parells d'enters
 */
void llegirCuaParInt(std::queue<ParInt>& c);
/**
 * 
 * @brief Escriu una cua de parells d'enters
 * 
 * @post cua escrita al canal de sortida
 */

void escriureCuaParInt(std::queue<ParInt> c);

#endif