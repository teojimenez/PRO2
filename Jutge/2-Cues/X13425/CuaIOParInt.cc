#include "CuaIOParInt.hh"
#include <iostream>

void llegirCuaParInt(queue<ParInt>& c)
{
	ParInt a;
	while (a.llegir())
		c.push(a);
}

void escriureCuaParInt(queue<ParInt> c)
{
	while (!c.empty())
    {
		// escriure(c.front());
        c.front().escriure();
		c.pop();
	}
}