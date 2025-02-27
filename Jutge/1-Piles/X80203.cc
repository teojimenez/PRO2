//Indexar seqüències ben parentitzades

//
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<char> fill_stack_reverse(string str)
{
    stack<char> stack;
    int size = str.length();

    for (int i = size - 1; i >= 0; i--)
        stack.push(str[i]);
    return stack;
}

//esta todo MAL
void reverse(stack<char> &stack, int &counter, vector <int> &parentesis)
{
    char open = '(';
    char close = ')';
    
    if (stack.empty())
        cout << endl;
    else if (stack.top() == open)
    {
        parentesis[0]++;
        stack.pop();
        counter++;
        cout << open << counter;

        reverse(stack, counter, parentesis);
    }
    else
    {
        parentesis[1]++;
        stack.pop();

        int number;
        if (parentesis[0] == parentesis[1] and !stack.empty())
        {
            number = (counter - parentesis[0]);
            if (number == 0)number++;
        }
        else
        {
            number = counter;
        }

        cout << close << number;
        reverse(stack, counter, parentesis);
    }
}

void parentesis(string str)
{
    stack<char> stack = fill_stack_reverse(str);

    int size = str.length();
    char open = '(';
    char close = ')';

    vector <int> parentesis = {0,0};

    int counter = 0;
    reverse(stack, counter, parentesis);
    // while (!stack.empty())
    // {
    //     if (stack.top() == open)
    //     {
    //         openCounter++;
    //         cout << open << openCounter;
    //     }
    //     else
    //     {
    //         closeCounter = size - stack.size();
    //         cout << close << closeCounter;
    //     }
    //     stack.pop();
    // }
    // cout << endl;
}

int main()
{
    string str;

    while (cin >> str)
    {
        parentesis(str);
    }
}