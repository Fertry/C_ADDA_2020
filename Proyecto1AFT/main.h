/*
 * main.h
 *
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 1
 *
 */


#ifndef MAIN_H_
#define MAIN_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/list.h"

// Cabeceras de las funciones:
list leeDatosEjercicio1 (char * fichero);
list compruebaSiEsPrimo (list lista);
bool esPrimo(long n);

int leeDatosEjercicio2 (char * fichero);
string primosHastaLimite (int limite);
int siguientePrimo (int numero);

#endif /* MAIN_H_ */
