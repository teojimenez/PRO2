//Avaluacio d'una expressio amb parentesis

//
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    char ch;
    stack <char> stack;

    cin >> ch;
    int count = 0;
    while (ch != '.')
    {
        if (ch == '(' or ch == '[')
            stack.push(ch);
        else if (!stack.empty() and ((ch == ')' and stack.top() == '(') or (ch == ']' and stack.top() == '[')))
            stack.pop();
        else if (ch != '.') //cas parentesis malament
        {
            ch = '.';
            stack.push('.');
        }
        if (ch != '.')  cin >> ch;
        ++count;
    }
    if (stack.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << ' ' << count << endl;
}