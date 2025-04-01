#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 12 // Por si se usa en otro lado

// (Opcional) Estructura auxiliar si la necesitas
typedef struct {
    char fecha[20];
    char nombre_pizza[50];
    int cantidad;
    float precio;
} Venta;

// DECLARACIONES DE FUNCIONES
int read_csv(const char *filename, Order **orders);
void free_memory(Order *orders);

#endif // UTILS_H
