
#include <list>
#include <string>
using namespace std;

list<string>::const_iterator longest(const list<string>& text)
{
    list<string>::const_iterator result = text.begin();

    //podem posar auto it i ens estalviem "list<string>::const_iterator"
    for (auto it = text.begin(); it != text.end(); it++)
    {
        if ((*it).length() > (*result).length()) result = it;
    }
    return result;
}