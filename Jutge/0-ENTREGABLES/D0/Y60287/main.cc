//Anti Cross-Site Scripting

// Rebem una pagina d'html a la qual hem de retornar la mateixa pagina pero amb els tags "script" esborrats quan:
// "script" no es fill directe de "html" i "head".

#include <iostream>
#include "html_elem.hh"
#include "vstack.hh"

using namespace std;

int main()
{
    string str;
    VStack pila;

    while (cin >> str)
    {
        //afegim / eliminem els tag segons entren
        if (is_tag(str))
        {
            cout << str << ' '; //es mostren els tags

            if (!is_close_tag(str))
                pila.push(tag_name(str));
            else
                pila.pop();
        }
        else
        {
            bool print_script = pila.size() > 2 && pila.top(0) == "script" && pila.top(-1) == "head" && pila.top(-2) == "html";

            //escriure paraules fora de tags o escriure contigut dins del script quan es: script < head < html
            if (!pila.contains("script") || print_script)
                cout << str << ' ';
        }
    }
}