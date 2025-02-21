#include <iostream>
#include <vector>
#include "color-printer.hh"
using namespace std;

int main() {
	ColorPrinter pr;
	char ch = '*';
	std::vector<pair<Color, char>> colors = {
		{Color::black, ch},   {Color::red, ch},		{Color::green, ch},
		{Color::yellow, ch}, {Color::blue, ch},	{Color::magenta, ch},
		{Color::cyan, ch},	   {Color::white, ch},
	};

	for (int i = 0; i < colors.size(); i++) {
		pr.set_color(colors[i].first);
		pr << colors[i].second << " ";
	}
	pr << endl;

	return 0;
}