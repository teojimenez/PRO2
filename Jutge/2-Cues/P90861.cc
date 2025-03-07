// Cues d'un supermercat (1)

//
//

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

void escriure_cues(vector <queue <string> > &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << "cua " << i + 1 << ":";
        while (!s[i].empty())
        {
            cout << " " << s[i].front();
            s[i].pop();
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector <queue <string> > supermercat(n);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string linea, nom;
        getline(cin, linea);    // llegeix tota la linea
        stringstream ss(linea); // converteix la linea en un flux d'entrada (com cin)
        while (ss >> nom)
            supermercat[i].push(nom);
    }

    cout << "SORTIDES" << endl << "--------" << endl;

    string accio;

    while (cin >> accio)
    {
        if (accio == "SURT")
        {
            int cua;
            cin >> cua;
            if (supermercat.size() >= cua and cua > 0 and supermercat[cua - 1].size() > 0)
            {
                cout << supermercat[cua - 1].front() << endl;
                supermercat[cua - 1].pop();
            }
        }
        else //nomes pot ser ENTRA
        {
            string nom;
            int cua;

            cin >> nom >> cua;
            if (supermercat.size() >= cua and cua > 0)
                supermercat[cua - 1].push(nom);
        }
    }
    cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    escriure_cues(supermercat);
}