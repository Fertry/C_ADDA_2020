/*
 * main.h
 *
 *  	Análisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernández Trigo
 *      Práctica Individual 1
 *
 */


#ifndef MAIN_H_
#define MAIN_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/list.h"
#include "types/math2.h"

// Cabeceras de las funciones:
list leeDatosEjercicio1 (char * fichero);
list compruebaSiEsPrimo (list lista);

int leeDatosEjercicio2 (char * fichero);
string primosHastaLimite (int limite);
int siguientePrimo (int numero);

#endif /* MAIN_H_ */
