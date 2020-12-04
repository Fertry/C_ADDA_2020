/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#ifndef EJERCICIOS_EJERCICIO1RECURSIVA_H_
#define EJERCICIOS_EJERCICIO1RECURSIVA_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/matrices.h"

// Cabeceras de las funciones:
bool ejercicio1Recursivo(matrix matriz);
bool ejercicio1RecursivoPrivado(matrix matriz);
matrix calculaMatrizPartidaEnCuatro(matrix matriz, int filaDePartida, int columnaDePartida);
bool extremosDistintosONo(matrix matriz);

#endif /* EJERCICIOS_EJERCICIO1RECURSIVA_H_ */
