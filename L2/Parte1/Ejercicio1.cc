#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;

    getline(cin, text);

    int k = text.find("trumpet");
    while (k > 0)
    {
        text.replace(k, 7, "[redacted]");
        k = text.find("trumpet");
    }
    cout << text << endl;
}