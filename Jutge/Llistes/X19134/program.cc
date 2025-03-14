
#include <iostream>
#include <list>
#include "LlistaIOParInt.hh"

using namespace std;



int main()
{
    list <ParInt> l;
    LlegirLlistaParInt(l);
    int n;
    cin >> n;
    ParInt result;

    for (auto it = l.begin(); it != l.end(); it++)
        if (it->primer() == n) result = ParInt(result.primer() + 1, result.segon() + it->segon());
    cout << n << " " << result.primer() << " " << result.segon() << endl;
}