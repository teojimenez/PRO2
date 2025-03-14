#include <string>
#include <vector>
using namespace std;

#include "player.hh"

/*
   Implementa la funció `winners` i envia només aquest fitxer al Jutge.
*/
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