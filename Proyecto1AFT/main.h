/*
 * main.h
 *
 *  	An�lisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fern�ndez Trigo
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

#endif /* MAIN_H_ */
