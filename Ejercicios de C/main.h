/*
 * main.h
 *
 *  Created on: 8 oct. 2020
 *      Author: Alejandro Fdez. Trigo
 */

#ifndef MAIN_H_
#define MAIN_H_

// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types/list.h"

// Cabeceras de las funciones:
float sumaListaReales(list lista);
int sumaListaEnteros(list lista);
double buscaPrimerMayorReal(list lista, double umbral);
list devuelveCoordenadaXDePuntos(list lista);
bool cumplenPredicado(list lista, bool (*predicado)(int e));
punto * devuelvePuntoConMayorX(list lista, int (*compara)(const void *, const void *));

#endif /* MAIN_H_ */
