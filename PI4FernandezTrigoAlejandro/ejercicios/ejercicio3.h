/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#ifndef EJERCICIOS_EJERCICIO3_H_
#define EJERCICIOS_EJERCICIO3_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/tree.h"

// Cabeceras de las funciones:
list leeDatosEjercicio3(char * fichero);
void funcionAuxiliarEjercicio3(list listaArboles);
list ejercicioPredicadoPar(list arboles, int arbol);
list ejercicioPredicadoPrimo(list arboles, int arbol);
list funcionAuxiliarPredicadoPar(list arboles, list resultado, list nivel, list lista, int arbol, int i);
list funcionAuxiliarPredicadoPrimo(list arboles, list resultado, list nivel, list lista, int arbol, int i);
bool predicadoPar(list arboles, bool resultado, int i);
bool predicadoPrimo(list arboles, bool resultado, int i);
//list calculaNivelArbol(tree * arbol, list nivelCero);

#endif /* EJERCICIOS_EJERCICIO3_H_ */
