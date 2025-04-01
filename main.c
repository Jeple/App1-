#include <stdio.h>
#include <stdlib.h>
#include "order.h"    // Primero estructuras
#include "utils.h"    // Luego funciones auxiliares
#include "metrics.h"  // Finalmente métricas

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <archivo CSV>\n", argv[0]);
        return 1;
    }

    const char *archivo = argv[1];
    Order *orders = NULL;
    int num_orders = read_csv(archivo, &orders);

    if (num_orders <= 0) {
        printf("No se pudo leer el archivo o está vacío.\n");
        return 1;
    }

    pizza_mas_vendida(orders, num_orders);     // Calcula y muestra pizza más vendida
    fecha_mas_ventas(orders, num_orders);      // Calcula y muestra fecha con más ventas

    free_memory(orders);  // Libera la memoria usada
    return 0;
}
