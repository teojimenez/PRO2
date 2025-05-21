
#include <iostream>
#include <sstream>
#include "html_elem.hh"
#include "vstack.hh"

using namespace std;

int main()
{
    string linea, contingut;
    VStack pila;

    bool imprimirScript = true;
    while (getline(cin, linea) && !linea.empty())
    {
        stringstream ss(linea);
    
        while (ss >> contingut)
        {
            if (is_tag(contingut)) //html // head //script
            {
                if (tag_name(contingut) == "html" || tag_name(contingut) == "head")
                {
                    if (!is_close_tag(contingut))
                        pila.push(tag_name(contingut));
                    else
                        pila.pop();
                }
                // mal format i no s'ha de imprimir
                else if (tag_name(contingut) == "script" and 
                (pila.size() != 2 && (pila.top(0) != "head" or pila.top(1) != "html")))
                        imprimirScript = false;
            }

            // imprimir
            //contempla casos script en linea i en diferents linees
            if (!imprimirScript)
            {
                if (is_tag(contingut)) cout << contingut << ' ';
                
                //elimina contingut de la linea actual
                while (!is_close_tag(contingut) && ss >> contingut);
                
                // verifica es tag de sortir de script i (cas que no esta en una sola linea)
                if (is_tag(contingut) && tag_name(contingut) == "script" && is_close_tag(contingut))
                {
                    imprimirScript = true;
                    cout << contingut << ' ';
                }
            }
            else
                cout << contingut << ' ';

        }
    }

}


//mirar tema de quan es script i borra varies linees a la vegada...(ara nomes borra la linea actual)
//fer-ho fins a trobar etiqueta de tancament script