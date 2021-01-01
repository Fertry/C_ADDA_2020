/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#ifndef EJERCICIOS_EJERCICIO5_H_
#define EJERCICIOS_EJERCICIO5_H_

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
list leeDatosEjercicio5(char * fichero);
void funcionAuxiliarEjercicio5(list listaArboles);
hash_table ejercicio5Interno(list arboles, int arbol);
hash_table ejercicio5(list arboles, int arbol, int i, int j, int k, hash_table resultado);
//list calculaNivelArbol(tree * arbol, list nivelCero);

#endif /* EJERCICIOS_EJERCICIO5_H_ */
