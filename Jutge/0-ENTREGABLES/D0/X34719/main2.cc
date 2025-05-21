#include <iostream>
#include <map>
#include <list>

using namespace std;

struct info {
    string  path;
    int     t;
};



void print_bots(map <string, list <info> > b)
{
    int count = 0;

    for (auto it_dicc = b.begin(); it_dicc != b.end(); it_dicc++)
    {
        if (it_dicc->second.size() >= 20)
        {
            
            ++count;
            auto &list = it_dicc->second; //referencia a list<info>
            cout << it_dicc->first;


            //ordenar
            list.sort([](const info &a, const info &b ){
                return a.path < b.path;  // ordenar segons path
            });

                // 2. Eliminar elementos duplicados por path
            list.unique([](const info& a, const info& b){
                return a.path == b.path;
            });

            //imprimir
            for (auto it_list = list.begin(); it_list != list.end(); it_list++)
            {
                cout << ' ' << it_list->path;
            }
            cout << endl;
        }
    }

    if (count  < 1) cout << "No bots" << endl;
}


int main()
{
    string ip, path;
    int t;

    map <string, list <info> > potencialBots;

    while (cin >> ip >> path >> t)
    {
        if (potencialBots.find(ip) != potencialBots.end())
        {
            potencialBots[ip].push_back({path, t});
            
            auto it = potencialBots[ip].end();
            if (potencialBots[ip].size() > 1)
                it = prev(potencialBots[ip].end(), 2);

            if ((t - it->t) > 99) //cas eliminar entrades que no son bots
            {
                auto &l = potencialBots[ip]; //crea un alias
                l.erase(l.begin(), prev(l.end()));
            }
        }
        else
            potencialBots[ip] = {{path, t}}; //inicialitzem el vector
    }

    print_bots(potencialBots);
}