
#include <iostream>
#include <vector>
using namespace std;

#include "player.hh"

vector<string> winners(vector<Player>::iterator ini, vector<Player>::iterator fin)
{
	if (ini == fin) return {};
	
	vector <string> result;
	int max = ini->score;
	while(ini != fin)
	{
		if (ini->score > max)
		{
			result = {ini->name};
			max = ini->score;
		}
		else if (ini->score == max) result.push_back(ini->name);
		ini++;
	}
	return result;
}

int main() {
	Player p;
	vector<Player> v;
	while (cin >> p.name >> p.score) {
		v.push_back(p);
	}
	vector<string> w = winners(v.begin(), v.end());
	for (int i = 0; i < w.size(); i++) {
		cout << (i == 0 ? "" : " ") << w[i];
	}
	cout << endl;
	return 0;
}
