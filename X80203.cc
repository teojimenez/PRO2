//Indexar seqüències ben parentitzades

//
//

#include <iostream>
#include <stack>
using namespace std;

void parentesis(string str)
{
    stack<int> open;
    int count = 0;
    
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
        {
            count++;
            cout << '(';
            open.push(count);
            cout << count;
        }
        else
        {
            cout << ')';
            cout << open.top();
            open.pop();
        }
    }
    cout << endl;
}

int main()
{
    string str;

    while (cin >> str)
    {
        parentesis(str);
    }
}