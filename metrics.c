/*Funciones de Calculo (Metricas)*/
#include <stdio.h>
#include <string.h>
#include "metrics.h"

// Función para encontrar la pizza más vendida
void pizza_mas_vendida(Order orders[], int num_orders) {
    PizzaMetrics pizzaMetrics[100] = {0}; // Array para almacenar las métricas de las pizzas
    int pizza_count = 0; // Número de pizzas diferentes encontradas

    // Iterar sobre todas las órdenes
    for (int i = 0; i < num_orders; i++) {
        int found = 0;

        // Verificar si la pizza ya está en el arreglo de métricas
        for (int j = 0; j < pizza_count; j++) {
            if (strcmp(orders[i].pizza_name, pizzaMetrics[j].pizza) == 0) {
                pizzaMetrics[j].cantidad++; // Aumentar la cantidad de esa pizza
                found = 1;
                break;
            }
        }

        // Si la pizza no está registrada, agregarla
        if (!found) {
            strcpy(pizzaMetrics[pizza_count].pizza, orders[i].pizza_name);
            pizzaMetrics[pizza_count].cantidad = 1;
            pizza_count++;
        }
    }

    // Buscar la pizza más vendida
    int max_cantidad = 0;
    char pizza_mas_vendida[100];
    for (int i = 0; i < pizza_count; i++) {
        if (pizzaMetrics[i].cantidad > max_cantidad) {
            max_cantidad = pizzaMetrics[i].cantidad;
            strcpy(pizza_mas_vendida, pizzaMetrics[i].pizza);
        }
    }

    // Mostrar el resultado
    printf("La pizza más vendida es: %s con %d ventas\n", pizza_mas_vendida, max_cantidad);
}

// Función para encontrar la fecha con más ventas
void fecha_mas_ventas(Order orders[], int num_orders) {
    int ventas_por_fecha[365] = {0}; // Array para contar las ventas por fecha
    int max_ventas = 0;
    int fecha_max_ventas = 0;

    // Contar las ventas por fecha
    for (int i = 0; i < num_orders; i++) {
        ventas_por_fecha[orders[i].date]++; // Asumimos que la fecha es un valor numérico
    }

    // Encontrar la fecha con más ventas
    for (int i = 0; i < 365; i++) {
        if (ventas_por_fecha[i] > max_ventas) {
            max_ventas = ventas_por_fecha[i];
            fecha_max_ventas = i;
        }
    }

    // Mostrar el resultado
    printf("La fecha con más ventas es el día %d con %d ventas\n", fecha_max_ventas, max_ventas);
}
