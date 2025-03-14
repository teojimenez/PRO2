//

//
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <string, string> map;
    string key;
    string value;

    while(cin >> key >> value)
    {
        map[key] = value;
        // map.insert(make_pair(key, value));
        // map.insert(pair <string, string>(key, value));
    }

    while (cin >> key)
    {
        if (map.find(key))
    }
}