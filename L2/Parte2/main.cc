// g++ -o fechas main.cc fecha.cc

#include <iostream>
#include <vector>
#include "fecha.hh"
using namespace std;

int main() {
	Fecha f(30, 12, 2024);
	cout << "La fecha por defecto: " << f << endl;

	Fecha hoy = Fecha::hoy();
	cout << "Hoy es: " << hoy << endl;

	Fecha en_7_dias = hoy.suma_dias(7);
	cout << "Dentro de una semana será: " << en_7_dias << endl;

	cout << "Todas las fechas hasta fin de mes:" << endl;
	Fecha fin_de_mes(1, hoy.mes() + 1, hoy.anyo());

	Fecha g = hoy;
	while (g.menor(fin_de_mes)) {
		cout << g << ' ';
		g = g.suma_dias(1);
	}
	cout << endl;

    f = f.suma_dias(1);
    cout << f << endl;
    f = f.suma_dias(1);
    cout << f << endl;
    f = f.suma_dias(35);
    cout << f << endl;
}
