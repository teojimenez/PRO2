#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @fn string join(vector<string> str, string separador)
 *
 * @brief Junta un texto con separadores apartir de un vctor de strings
 *
 * Ejemplo: `join({"hola", "adios"}, ",")` devuelve `"hola,adios"`
 *
 * @param vec vector a juntar
 * @param sep Separador
 *
 * @pre: `sep.length() >= 0`. Si `sep` está vacío, no se separan los strings.
 *
 * @return `string` Texto juntado
 */
string join(vector<string> vec, string sep)
{
    string result;

    for (int i = 0; i < vec.size(); i++)
    {
        if (i > 0)result += sep;
        result += vec[i];
    }
    return result;
}


int main()
{
    vector <string> vec = {"hola", "adios", "31231", "C++"};
    cout << join(vec, "/") << endl;
}