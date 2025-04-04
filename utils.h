/*Prototipos Funciones auxiliares, lectura de CSV*/
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELDS 5

// Estructura para almacenar una venta
typedef struct {
    char fecha[20];
    char nombre_pizza[50];
    int cantidad;
    float precio;
} Venta;

// Función para contar el número de líneas en el archivo CSV
int contar_lineas_csv(const char *nombre_archivo);

// Función para leer el archivo CSV y almacenar los datos en un array de estructuras Venta
Venta *leer_csv(const char *nombre_archivo, int *num_ventas);

#endif // UTILS_H

