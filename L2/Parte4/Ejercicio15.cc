#include <iostream>
#include <vector>
#include <string>
#include "color-printer.hh"
using namespace std;

int main()
{
    string text;
    getline(cin, text);
	ColorPrinter pr;
    int k = text.find("trumpet");
    while (k > 0)
    {
        string rd = "[redacted]";
		pr.set_color(Color::red);
		pr << rd;
		text.replace(k, 7, rd);
        k = text.find("trumpet");
    }
    cout << text << endl;
}