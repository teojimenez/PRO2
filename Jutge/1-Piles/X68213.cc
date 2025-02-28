// Biblioteca

//
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void escriure_pila(stack <string> llibres)
{
    stack <string> temp;

    int size = llibres.size();
    for (int i = 0; i < size; i++)
    {
        cout << llibres.top() << endl;
        temp.push(llibres.top());
        llibres.pop();
    }

    size = temp.size();
    for (int i = 0; i < size; i++)
    {
        llibres.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector <stack <string> > biblioteca(n);
    cin >> n;
    while (n != -4)
    {
        if (n == -1)
        {
            string libro;
            int categoria;
            cin >> libro >> categoria;
            biblioteca[categoria - 1].push(libro);
        }
        else if (n == -2)
        {
            int num_libros;
            int categoria;
            cin >> num_libros >> categoria;
            for (int i = 0; i < num_libros; i++)
            {
                biblioteca[categoria - 1].pop();
            }
        }
        else if (n == -3)
        {
            int categoria;
            cin >> categoria;
            cout << "Pila de la categoria " << categoria << endl;
            escriure_pila(biblioteca[categoria - 1]);
        }
        cin >> n;
    }
}