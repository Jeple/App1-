/* Prototipos Funciones de Calculo (Metricas), header */
#ifndef METRICS_H
#define METRICS_H

#include "order.h"   // Estructura Order
#include "utils.h"   // Para funciones auxiliares

// Estructura auxiliar para métricas de pizzas
typedef struct {
    char pizza[100];    // nombre de la pizza
    int cantidad;       // cantidad vendida
} PizzaMetrics;

// Declaración de funciones de métricas
void pizza_mas_vendida(Order orders[], int num_orders);     // pms
void fecha_mas_ventas(Order orders[], int num_orders);      // dms
void fecha_menor_ventas(Order orders[], int num_orders);    // dls
void fecha_mas_pizzas(Order orders[], int num_orders);      // dmsp

#endif // METRICS_H
//Subir solo esto