/*
 *  	Analisis y Diseño de Datos y Algoritmos - 2020
 *      Author: Alejandro Fernandez Trigo
 *      Practica Individual 3
 */

#ifndef EJERCICIOS_EJERCICIO4RECURSIVACONMEMORIA_H_
#define EJERCICIOS_EJERCICIO4RECURSIVACONMEMORIA_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/math2.h"
#include "types/types.h"
#include "types/list.h"
#include "types/hash_table.h"

// Cabeceras de las funciones:
int ejercicio4RecursivoConMemoria (int numeroA, int numeroB);
int ejercicio4RecursivoConMemoriaInterno (int numeroA, int numeroB, hash_table * memoria);

#endif /* EJERCICIOS_EJERCICIO4RECURSIVACONMEMORIA_H_ */
