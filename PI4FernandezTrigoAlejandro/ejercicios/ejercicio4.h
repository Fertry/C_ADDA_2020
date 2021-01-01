/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#ifndef EJERCICIOS_EJERCICIO4_H_
#define EJERCICIOS_EJERCICIO4_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/tree.h"
#include "types/hash_table.h"

// Cabeceras de las funciones:
list leeDatosEjercicio4(char * fichero);
void funcionAuxiliarEjercicio4(list listaArboles);
hash_table ejercicio4Interno(list arboles, int arbol);
hash_table ejercicio4(list arboles, hash_table resultado, int arbol, int i);
list predicado(list listaEntrada, list listaSalida, int i);
//list calculaNivelArbol(tree * arbol, list nivelCero);

#endif /* EJERCICIOS_EJERCICIO4_H_ */
