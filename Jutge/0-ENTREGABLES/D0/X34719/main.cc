// Scraper bots

// Programa en el que rebem els registros fets a una web, amb la ip, adreça i el temps de connexió
// Amb aquestes dades hem de detectar si hi han bots
// Hi haurà bots si una mateixa ip té 20 accesos consecutius quan entre ells no hi ha mes diferencia de 100t.

#include <iostream>
#include <map>
#include <set>
#include <list>

using namespace std;

struct info {
    string  path;
    int     t;
};

/**
 * @brief Verifica que hi hagin 20 subsequencies amb temps < 100 entre elles
 * 
 * @param b una llista de estrcutura de dades info amb un path i un temps
 * 
 * @returns true si la direccio ip es un bot, o fals en cas contrari
 */
bool check_bot(list <info> &l)
{
    if (l.size() < 20) return false; // no pot ser bot

    auto it_start = l.begin();
    auto it_current = next(it_start); // inicialitzem al seguent valor
    int count = 1;

    while (it_current != l.end())
    {
        // verifiquem que sigui bot
        if (it_current->t - prev(it_current)->t < 100)
        {
            ++count;
            if (count == 20) return true; //es bot
        }
        else // reiniciem contador per veure si les segeunts 20 subsequencies fan que sigui bot
            count = 1;

        ++it_current;
    }
    return false; // no s'ha trobat cap subseqüència vàlida
}


/**
 * @brief Imprimeix els bots ordenats lexicograficament i en cas de no haver-ne, 
 *        imprimeix "no bots"
 * @param b diccionari amb ip's que equivalen a una llista de les peticions que s'han fet
 *          a la web.
 */
void print_bots(map <string, list <info> > &b)
{
    int count = 0;

    for (auto it_dicc = b.begin(); it_dicc != b.end(); it_dicc++)
    {
        auto &l = it_dicc->second;
        //verifiquem que sigui bot
        if (check_bot(l))
        {
            ++count;
            set<string> paths;
            //ho convertim a un conjunt per evitar repeticions i perque estigui ordenat
            for (auto it_list = l.begin(); it_list != l.end(); it_list++)
                paths.insert(it_list->path);
            
            //imprimir els bots
            cout << it_dicc->first;
            for (auto it = paths.begin(); it != paths.end(); ++it)
                cout << ' ' << *it;

            cout << '\n';
        }
    }
    if (count < 1) cout << "No bots" << endl;
}


int main()
{
    string ip, path;
    int t;

    map <string, list <info> > potencialBots;

    //afegim/creem els diccionaris i tambe afegim les llistes
    while (cin >> ip >> path >> t)
        potencialBots[ip].push_back({path, t});
    //imprimeix i verifica que siguin bots
    print_bots(potencialBots);
}