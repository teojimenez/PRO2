#include <iostream>
#include <vector>
using namespace std;

string join(vector<string>::iterator begin, vector<string>::iterator end, string sep)
{
    string result;
    for (auto it = begin; it != end; it++)
        result += ((it == begin) ? "" : sep ) + *it;
    return result;
}