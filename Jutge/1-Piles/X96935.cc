//Palíndroms amb piles

//
//

#include <iostream>
#include <stack>
using namespace std;

bool palindrome(stack<int> &Pila, int n)
{
    int w;
    for (int i = 0; i < n/2; i++) 
    {
        cin >> w;
        Pila.push(w);
    }
    if (n % 2 != 0) cin >> w;

    bool palindrome = true;
    n = n / 2;
    while (palindrome and n > 0)
    {
        cin >> w;
        if (Pila.top() != w) palindrome = false;
        Pila.pop();
        --n;
    }
    return palindrome;
}

int main()
{
    int n;
    cin >> n;
    stack<int> Pila;

    cout << (palindrome(Pila, n) ? "SI" : "NO") << endl;
}