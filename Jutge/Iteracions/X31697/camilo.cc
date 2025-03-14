#include <list>
#include <string>
using namespace std;

void inserta_don(list<string>& texto)
{
    for (auto it = texto.begin(); it != texto.end(); it++)
        if (*it == "Camilo") texto.insert(it, "Don");
}