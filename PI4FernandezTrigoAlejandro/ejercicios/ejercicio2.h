/*
 *  	Analisis y Dise�o de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#ifndef EJERCICIOS_EJERCICIO2_H_
#define EJERCICIOS_EJERCICIO2_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/tree.h"

// Cabeceras de las funciones:
list leeDatosEjercicio2Arboles(char * fichero);
list leeDatosEjercicio2Listas(char * fichero);
void funcionAuxiliarEjercicio2(list listaArboles, list listaLetras);
bool ejercicio2Interno(binary_tree * arbol, list lista);
bool ejercicio2(binary_tree * arbol, list lista, int i);

#endif /* EJERCICIOS_EJERCICIO2_H_ */
