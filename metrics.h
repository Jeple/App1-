/* Prototipos Funciones de Calculo (Metricas), header */
#ifndef METRICS_H
#define METRICS_H

#include "utils.h"   // Para funciones auxiliares

// Estructura auxiliar para métricas de pizzas
typedef struct {
    char pizza[100];    // nombre de la pizza
    int cantidad;       // cantidad vendida
} PizzaMetrics;

// Función para encontrar la pizza más vendida
void pizza_mas_vendida(Order orders[], int num_orders);

// Función para encontrar la fecha con más ventas (en dinero)
void fecha_mas_ventas(Order orders[], int num_orders);

// Función para encontrar la fecha con menos ventas (en dinero)
void fecha_menor_ventas(Order orders[], int num_orders);

// Función para encontrar la fecha con más pizzas vendidas (cantidad)
void fecha_mas_pizzas(Order orders[], int num_orders);

// Función para encontrar la pizza menos vendida
void pizza_menos_vendida(Order orders[], int num_orders);

// Función para encontrar la fecha con menos pizzas vendidas
void fecha_menos_pizzas(Order orders[], int num_orders);

// Función para calcular el promedio de pizzas por orden
void promedio_pizzas_por_orden(Order orders[], int num_orders);

// Función para calcular el promedio de pizzas por día
void promedio_pizzas_por_dia(Order orders[], int num_orders);

// Función para encontrar el ingrediente más vendido
void ingrediente_mas_vendido(Order orders[], int num_orders);

// Función para contar cuántas pizzas fueron vendidas por categoría
void cantidad_pizzas_por_categoria(Order orders[], int num_orders);

#define pms pizza_mas_vendida        // Alias abreviado
#define pls pizza_menos_vendida      // Alias abreviado
#define dms fecha_mas_ventas  // Alias abreviado
#define dls fecha_menor_ventas // Alias abreviado
#define dmsp fecha_mas_pizzas // Alias abreviado
#define dlsp fecha_menos_pizzas // Alias abreviado
#define apo promedio_pizzas_por_orden  // Alias abreviado
#define apd promedio_pizzas_por_dia  // Alias abreviado
#define ims ingrediente_mas_vendido  // Alias abreviado
#define hp cantidad_pizzas_por_categoria  // Alias abreviado

#endif // METRICS_H
//Subir solo esto