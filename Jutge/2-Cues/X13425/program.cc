// Distribucio justa de cues

//
//

#include <iostream>
#include <queue>
#include "CuaIOParInt.hh"

using namespace std;


/**
 * @brief distribucio de dues cues de parells
 * 
 * @param cua_inicial Cua amb parells d'enters amb un identificador d'usuari i temps de la gestio
 * @param a,b cua buida
 * 
 * @pre cua amb parells i dues cues resultats buides
 * @post cua a i b amb parells repartits
 * 
 */
void distribucio(queue<ParInt> &cua_inicial, queue<ParInt> &b, queue<ParInt> &a)
{
    // Cap persona esperi més a la nova cua que una que tenia al darrera inicialment.
    // Totes esperin el mínim temps possible.
    // Si un usuari pot anar a les dues cues, s’escollira la primera.
    int count_a = 0, count_b = 0;

    while (!cua_inicial.empty())
    {
        if (count_a < count_b)
        {
            a.push(cua_inicial.front());
            count_a += cua_inicial.front().segon();
        }
        else
        {
            b.push(cua_inicial.front());
            count_b += cua_inicial.front().segon();
        }
        cua_inicial.pop();
    }
}


int main()
{
    queue<ParInt> cua_inicial;
    llegirCuaParInt(cua_inicial);
    queue<ParInt> cua_a, cua_b;
    
    distribucio(cua_inicial, cua_a, cua_b);
    escriureCuaParInt(cua_a);
    cout << endl;
    escriureCuaParInt(cua_b);
}