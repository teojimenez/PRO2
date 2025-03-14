#ifndef Llista_IO_Par_Int_HH
#define Llista_IO_Par_Int_HH

#include "ParInt.hh"
#include "list"

void LlegirLlistaParInt(list<ParInt>& l);
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)

void EscriureLlistaParInt(const list<ParInt>& l); //(opcional)
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l

#endif