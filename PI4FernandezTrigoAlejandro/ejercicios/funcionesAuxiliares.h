/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 4
 */

#ifndef EJERCICIOS_FUNCIONESAUXILIARES_H_
#define EJERCICIOS_FUNCIONESAUXILIARES_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/tree.h"

// Cabeceras de las funciones:
int * castearArbol(int * numeroA, char * numeroB);
list calculaSiguienteNivel(list nivelCero);
int calculaAlturaArbol(tree * arbol);
list calculaNivelArbol(tree * arbol, int i);

#endif /* EJERCICIOS_FUNCIONESAUXILIARES_H_ */
