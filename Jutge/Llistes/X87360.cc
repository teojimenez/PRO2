#include <list>
#include <iostream>
using namespace std;

void inter(list<int>& uno, const list<int>& dos )
{
    auto it1 = uno.begin();
    auto it2 = dos.begin();
    while (it1 != uno.end())
    {
        bool trobat = false;
        while (!trobat && it2 != dos.end() && (*it1 >= *it2))
        {
            if (*it1 == *it2) trobat = true;
            else it2++;
        }
        (trobat) ? it1++ : it1 = uno.erase(it1);
    }
}
/*
void print_list(list <int> l)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout <<((it == l.begin() ? "" : " ")) << *it;
    }
    cout << endl;
    
}

int main()
{
    list <int> uno = {-7, 1, 5, 12};
    list <int> dos = {1, 3, 4, 5};

    inter(uno, dos);

    print_list(uno);
}*/