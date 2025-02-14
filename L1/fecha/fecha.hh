
#ifndef FECHA_HH
#define FECHA_HH

#include <vector>
#include <iostream>

struct Fecha {
	int dia_, mes_, anyo_;
};

/**
 * @brief Lee una fecha en formato DD/MM/AAAA.
 */
Fecha fecha_leer();

/**
 * @brief Escribe una fecha en formato DD/MM/AAAA.
 */
void fecha_escribir(const Fecha& f);

/**
 * @brief Determina si un anyo es bisiesto.
 *
 * @param anyo El anyo a comprobar.
 */
bool es_bisiesto(int anyo);

/**
 * @brief Determina el número de días de un mes
 *
 * @param mes El mes a comprobar.
 * @param anyo El anyo al que pertenece el mes.
 *
 * @return El número de días del mes.
 */
int dias_mes(int mes, int anyo);

/**
 * @brief Añade un número de días a una fecha.
 *
 * @param f La fecha a la que añadir los días.
 * @param dias El número de días a añadir.
 */
Fecha fecha_sumar_dias(const Fecha& f, int dias);

/**
 * @brief Operador de escritura para fechas.
 *
 * Este operador define el comportamiento de `cout << f;` donde `f` es una fecha.
 *
 * @param o El `stream` de salida (`cout` u otro).
 * @param f La fecha a escribir.
 *
 * @return El mismo `stream` de salida para permitir encadenar salidas.
 *
 * @pre `f` es una fecha válida.
 */
std::ostream& operator<<(std::ostream& out, const Fecha& f);

/**
 * @brief Operador de lectura para fechas.
 *
 * Este operador define el comportamiento de `cin >> f;` donde `f` es una fecha.
 *
 * @param in El `stream` de entrada (`cin` u otro).
 * @param f La fecha a leer.
 */
std::istream& operator>>(std::istream& in, Fecha& f);

/**
 * @brief Devuelve `true` si `a` es anterior a `b`, `false` en caso contrario.
 */
bool fecha_menor(const Fecha& a, const Fecha& b);

/**
 * @brief Devuelve la fecha actual.
 */
Fecha fecha_actual();

/**
 * @brief Leer secuencia de fechas de un fichero
 * @param filename Nombre del fichero
 * @return `vector` con las fechas leídas
 */
std::vector<Fecha> leer_fechas_de_fichero(const std::string& filename);


#endif