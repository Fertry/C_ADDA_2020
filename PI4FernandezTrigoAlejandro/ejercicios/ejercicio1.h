/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#ifndef EJERCICIOS_EJERCICIO1_H_
#define EJERCICIOS_EJERCICIO1_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/tree.h"

// Cabeceras de las funciones:
list leeDatosEjercicio1(char * fichero);
void funcionAuxiliarEjercicio1(list listaArboles);
bool ejercicio1(binary_tree * arbol);
bool esBinario(binary_tree * arbol);

#endif /* EJERCICIOS_EJERCICIO1_H_ */
