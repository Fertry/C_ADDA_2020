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
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"

// Cabeceras de las funciones:
// Primer ejercicio
list leeDatosEjercicio1(char *fichero);
list compruebaSiEsPrimo(list lista);

// Segundo ejercicio
int leeDatosEjercicio2(char *fichero);
string primosHastaLimite(int limite);
void funcionAuxiliarEjercicio2(list lista);

// Tercer ejercicio
void leeDatosEjercicio3(char *fichero);

#endif /* MAIN_H_ */
