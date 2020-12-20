/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#ifndef EJERCICIOS_EJERCICIO2RECURSIVA_H_
#define EJERCICIOS_EJERCICIO2RECURSIVA_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "ejemplos/tupla.h"

// Cabeceras de las funciones:
smax ejercicio2Recursivo(list lista);
smax ejercicio2RecursivoInterno(list lista, int inicio, int fin);
smax calculaSecuenciaMitad(list lista, int i, int j, int k);

#endif /* EJERCICIOS_EJERCICIO2RECURSIVA_H_ */
