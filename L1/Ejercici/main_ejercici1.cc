#include "../rng/rng.hh"
#include "../fecha/fecha.hh"
using namespace std;
#include <iostream>

const int NUM_FECHAS = 10000;
const int MAX_DISTANCIA = 30;

int main()
{   
    Fecha f;
    f = fecha_actual();
    RNG rng;

    rng_init(rng);
    for (int i = 0; i < NUM_FECHAS; i++)
    {
        int x = rng_generate(rng, 0, MAX_DISTANCIA);
        f = fecha_sumar_dias(f, x);
        cout << f << endl;
    }
    
}