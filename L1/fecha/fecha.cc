
#include <ctime>	// time, localtime, tm, ...
#include <fstream>	// Leer y escribir ficheros
#include <iomanip>	// setfill, setw
#include <iostream>
#include <vector>
using namespace std;

#include "fecha.hh"

Fecha fecha_leer() {
	char  sep;	// Leemos el separador pero no lo usamos
	Fecha f;
	cin >> f.dia_ >> sep >> f.mes_ >> sep >> f.anyo_;
	return f;
}

void fecha_escribir(const Fecha& f) {
	cout << setfill('0') << setw(2) << f.dia_;
	cout << '/' << setfill('0') << setw(2) << f.mes_;
	cout << '/' << setfill('0') << setw(4) << f.anyo_;
}

bool es_bisiesto(int anyo) {
	return (anyo % 4 == 0 && anyo % 100 != 0) || anyo % 400 == 0;
}

int dias_mes(int mes, int anyo) {
	if (mes == 2) {
		return es_bisiesto(anyo) ? 29 : 28;
	} else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		return 30;
	} else {
		return 31;
	}
}

Fecha fecha_sumar_dias(const Fecha& f, int dias) {
	Fecha res = f;
	res.dia_ += dias;
	while (res.dia_ > dias_mes(res.mes_, res.anyo_)) {
		res.dia_ -= dias_mes(res.mes_, res.anyo_);
		res.mes_++;
		if (res.mes_ > 12) {
			res.mes_ = 1;
			res.anyo_++;
		}
	}
	return res;
}


ostream& operator<<(ostream& out, const Fecha& f) {
	out << setfill('0') << setw(2) << f.dia_;
	//posa 0's de setw() tamany, en cas necesari
	out << '/' << setfill('0') << setw(2) << f.mes_;
	out << '/' << setfill('0') << setw(4) << f.anyo_;
	return out;
}

istream& operator>>(istream& in, Fecha& f) {
	char sep;  // Leemos el separador pero no se usa
	in >> f.dia_ >> sep >> f.mes_ >> sep >> f.anyo_;
	return in;
}

bool fecha_menor(const Fecha& a, const Fecha& b) {
	if (a.anyo_ != b.anyo_) {
		return a.anyo_ < b.anyo_;
	} else if (a.mes_ != b.mes_) {
		return a.mes_ < b.mes_;
	} else {
		return a.dia_ < b.dia_;
	}
}

Fecha fecha_actual() {
	time_t t = time(nullptr);
	tm	  *now = localtime(&t);
	// `now` es un puntero. Veremos punteros en la segunda parte del curso.

	Fecha f;
	f.dia_ = now->tm_mday;
	f.mes_ = now->tm_mon + 1;
	f.anyo_ = now->tm_year + 1900;
	return f;
}

vector<Fecha> leer_fechas_de_fichero(const string& filename) {
	vector<Fecha> res;
	ifstream	  fin(filename);

	Fecha f;
	while (fin >> f) {
		res.push_back(f);
	}
	return res;
}
