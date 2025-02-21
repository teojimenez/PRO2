#include <iostream>
#include <vector>
#include "fecha.hh"
using namespace std;

void sort_fechas(vector<Fecha> &vec)
{
    int i = 0;
    while (i < vec.size() - 1)
    {
        for (int j = 0; j < vec.size() - i - j; j++)
        {
            if (vec[j].mayor(vec[j + 1]))
            {
                swap(vec[j], vec[j + 1]);
            }
        }
        i++;
    }
}

int main()
{
    Fecha f;
    vector<Fecha> vec;
    while (cin >> f)
    {
        vec.push_back(f);
    }
    sort_fechas(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}