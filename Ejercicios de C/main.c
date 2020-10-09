/*
 * main.c
 *
 *  Created on: 6 oct. 2020
 *      Author: Alejandro Fdez. Trigo
 */
#include "main.h"


// Función de ejecución:
int main() {

	printf("Hola mundo!\n");

	char mem[256];
	char * coordenadasX;

	double numerosReales[] = { 45., 56, 90., 1., 23., 78., 76. };
	list listaReales = list_of(numerosReales, 7, double_type);
	long numerosEnteros[] = { 6, 7, 9, 12, 1, 7, 15, 5 };
	list listaEnteros = list_of(numerosEnteros, 8, int_type);
	punto puntos[] = { {2.4, 3.7}, {3.0, 5.1}, {5.0, 1.2} };
	list listaPuntos = list_of(puntos, 3, punto_type);

	double sumaReales = 0.0;
	long sumaEnteros = 0;
	double primerMayor = 0;
	double umbral = 60.0;

	sumaReales = sumaListaReales(listaReales);
	sumaEnteros = sumaListaEnteros(listaEnteros);
	primerMayor = buscaPrimerMayorReal(listaReales, umbral);
	list listaCoordenadasX = devuelveCoordenadaXDePuntos(listaPuntos);
	coordenadasX = list_tostring(&listaCoordenadasX, mem);
	bool verificaPredicado = cumplenPredicado(listaEnteros, es_par);
	punto * p = devuelvePuntoConMayorX(listaPuntos, punto_naturalorder);

	printf("Suma = %0.2lf\n", sumaReales);
	printf("Suma = %ld\n", sumaEnteros);
	printf("El primer real mayor a %0.2lf es el %0.2lf\n", umbral, primerMayor);
	printf("Lista coordenadas X: %s\n", coordenadasX);
	printf("Lista puntos cumplen predidado: %s\n", verificaPredicado ? "true" : "false");
	printf("Punto con mayor X: %s\n", punto_tostring(p, mem));

}

// Dada una lista de nº reales, devolver su suma:
float sumaListaReales(list lista) {

	float suma = 0.0;
	for (int i=0;i<lista.size;i++) {

			suma = suma + *(double*) list_get(&lista,i);

	}

	return suma;

}

// Dada una lista de nº enteros, sumar los cuadrados de todos los elementos de la lista:
int sumaListaEnteros(list lista) {

	int suma = 0;
	for (int i=0;i<lista.size;i++) {

		int numero = *(int*) list_get(&lista,i);
		int cuadrado = numero * numero;

		suma = suma + cuadrado;

	}

	return suma;

}

// Dada una lista de nº reales, buscar el primero que sea mayor a un umbral dado:
double buscaPrimerMayorReal(list lista, double umbral) {

	double resultado;
	int primero = 0;
	int i = 0;
	while (i < lista.size && primero == 0) {

		double numero = *(double*) list_get(&lista,i);

		if (numero > umbral) {

			resultado = numero;
			primero += 1;

		}

		i++;

	}

	return resultado;

}

// Dada una lista de objetos de tipo Punto, devolver otra con la coordenada X de esos puntos:
list devuelveCoordenadaXDePuntos(list lista) {

	list resultado = list_empty(double_type);
	for (int i=0;i<lista.size;i++) {

		double coordenadaX = (*(punto*) list_get(&lista,i)).x;
		list_add(&resultado, &coordenadaX);

	}

	return resultado;

}

// Dada una lista de enteros, comprobar si todos cumplen un predicado:
// Predicados: es_par y es_impar ya definidos
bool cumplenPredicado(list lista, bool (*predicado)(int e)) {

	bool resultado = true;

	int i = 0;
	while (i<lista.size && resultado) {

		resultado = predicado(*(int*) list_get(&lista,i));
		i++;

	}

	return resultado;

}

// Dada una lista de puntos, buscar el de mayor coordenada X:
punto * devuelvePuntoConMayorX(list lista, int (*cmp)(const void *, const void *)) {

	punto * resultado = NULL;
	for (int i=0;i<lista.size;i++) {

		punto * p = (punto *) list_get(&lista,i);
		if (resultado == NULL || cmp(p, resultado) > 0) {

			resultado = p;

		}

	}

	return resultado;

}
