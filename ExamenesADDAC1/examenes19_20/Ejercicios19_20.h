/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Exámenes del 1º cuatrimestre de ADDA
 */

#ifndef EXAMENES19_20_EJERCICIOS19_20_H_
#define EXAMENES19_20_EJERCICIOS19_20_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/tree.h"
#include "types/hash_table.h"

// Cabeceras de las funciones:
long solucionIterativa(int n, int k);
long solucionRecursiva(int n, int k);
long solucionRecursivaInterna(int n, int k, int e, long resultado);
bool secuencia (char * letras);

#endif /* EXAMENES19_20_EJERCICIOS19_20_H_ */
