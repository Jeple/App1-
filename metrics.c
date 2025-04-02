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
       
        // Imprimir cada pizza que estamos leyendo del archivo CSV
        printf("Leyendo pizza: %s\n", orders[i].pizza_name); // Verificar qué pizza se está leyendo
        
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
    
    // Mostrar todas las pizzas y sus cantidades (para depuración)
    printf("Pizzas registradas y sus cantidades:\n");
    for (int i = 0; i < pizza_count; i++) {
        printf("Pizza: %s, Cantidad: %d\n", pizzaMetrics[i].pizza, pizzaMetrics[i].cantidad);
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

// Función para encontrar la fecha con más ventas (en dinero)
void fecha_mas_ventas(Order orders[], int num_orders) {
    char fechas_unicas[500][20];       // Array para guardar fechas únicas (ej: "1/1/2015")
    float ventas_por_fecha[500] = {0}; // Array para acumular ventas totales por cada fecha
    int fechas_count = 0;              // Contador de fechas distintas encontradas

    // Recorrer todas las órdenes y agrupar por fecha
    for (int i = 0; i < num_orders; i++) {
        int encontrada = 0;

        // Verificar si la fecha ya fue registrada
        for (int j = 0; j < fechas_count; j++) {
            if (strcmp(orders[i].order_date, fechas_unicas[j]) == 0) {
                ventas_por_fecha[j] += orders[i].total_price; // Sumar total vendido ese día
                encontrada = 1;
                break;
            }
        }

        // Si la fecha no estaba registrada, agregarla al array
        if (!encontrada) {
            strcpy(fechas_unicas[fechas_count], orders[i].order_date);       // Copiar la fecha al array
            ventas_por_fecha[fechas_count] = orders[i].total_price;          // Inicializar con el total actual
            fechas_count++;
        }
    }

    // Buscar la fecha con más ventas
    float max_ventas = 0;
    char fecha_max[20] = "";

    for (int i = 0; i < fechas_count; i++) {
        if (ventas_por_fecha[i] > max_ventas) {
            max_ventas = ventas_por_fecha[i];           // Guardar el nuevo máximo
            strcpy(fecha_max, fechas_unicas[i]);        // Guardar la fecha correspondiente
        }
    }

    // Mostrar el resultado final
    printf("📈 La fecha con más ventas (dinero) es: %s con un total de $%.2f\n", fecha_max, max_ventas);
}

// Función para encontrar la fecha con menos ventas (en dinero)
void fecha_menor_ventas(Order orders[], int num_orders) {
    char fechas_unicas[500][20];       // Array para guardar fechas únicas
    float ventas_por_fecha[500] = {0}; // Array para acumular ventas por fecha
    int fechas_count = 0;              // Cantidad de fechas distintas encontradas

    // Recorrer todas las órdenes y agrupar por fecha
    for (int i = 0; i < num_orders; i++) {
        int encontrada = 0;

        // Buscar si la fecha ya fue registrada
        for (int j = 0; j < fechas_count; j++) {
            if (strcmp(orders[i].order_date, fechas_unicas[j]) == 0) {
                ventas_por_fecha[j] += orders[i].total_price;
                encontrada = 1;
                break;
            }
        }

        // Si no está, la agregamos
        if (!encontrada) {
            strcpy(fechas_unicas[fechas_count], orders[i].order_date);
            ventas_por_fecha[fechas_count] = orders[i].total_price;
            fechas_count++;
        }
    }

    // Buscar la fecha con menos ventas (pero mayor a cero)
    float min_ventas = ventas_por_fecha[0];
    char fecha_min[20];
    strcpy(fecha_min, fechas_unicas[0]);

    for (int i = 1; i < fechas_count; i++) {
        if (ventas_por_fecha[i] < min_ventas) {
            min_ventas = ventas_por_fecha[i];
            strcpy(fecha_min, fechas_unicas[i]);
        }
    }

    // Mostrar el resultado
    printf("📉 La fecha con MENOS ventas (dinero) es: %s con un total de $%.2f\n", fecha_min, min_ventas);
}
// Función para encontrar la fecha con más pizzas vendidas (cantidad)
void fecha_mas_pizzas(Order orders[], int num_orders) {
    char fechas_unicas[500][20];     // Para almacenar fechas únicas
    int pizzas_por_fecha[500] = {0}; // Para contar pizzas por fecha
    int fechas_count = 0;

    for (int i = 0; i < num_orders; i++) {
        int encontrada = 0;

        // Buscar si la fecha ya está registrada
        for (int j = 0; j < fechas_count; j++) {
            if (strcmp(orders[i].order_date, fechas_unicas[j]) == 0) {
                pizzas_por_fecha[j] += orders[i].quantity;
                encontrada = 1;
                break;
            }
        }

        // Si no está registrada, la agregamos
        if (!encontrada) {
            strcpy(fechas_unicas[fechas_count], orders[i].order_date);
            pizzas_por_fecha[fechas_count] = orders[i].quantity;
            fechas_count++;
        }
    }

    // Buscar la fecha con más pizzas
    int max_pizzas = 0;
    char fecha_max[20] = "";

    for (int i = 0; i < fechas_count; i++) {
        if (pizzas_por_fecha[i] > max_pizzas) {
            max_pizzas = pizzas_por_fecha[i];
            strcpy(fecha_max, fechas_unicas[i]);
        }
    }

    printf("🍕 La fecha con MÁS pizzas vendidas es: %s con %d pizzas\n", fecha_max, max_pizzas);
}

// Función para encontrar la pizza menos vendida
void pizza_menos_vendida(Order orders[], int num_orders) {
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

    // Buscar la pizza menos vendida
    int min_cantidad = pizzaMetrics[0].cantidad;
    char pizza_menos_vendida[100];
    strcpy(pizza_menos_vendida, pizzaMetrics[0].pizza);

    for (int i = 1; i < pizza_count; i++) {
        if (pizzaMetrics[i].cantidad < min_cantidad) {
            min_cantidad = pizzaMetrics[i].cantidad;
            strcpy(pizza_menos_vendida, pizzaMetrics[i].pizza);
        }
    }

    // Mostrar el resultado
    printf("La pizza menos vendida es: %s con %d ventas\n", pizza_menos_vendida, min_cantidad);
}

// Función para encontrar la fecha con menos pizzas vendidas
void fecha_menos_pizzas(Order orders[], int num_orders) {
    char fechas_unicas[500][20];     // Para almacenar fechas únicas
    int pizzas_por_fecha[500] = {0}; // Para contar pizzas por fecha
    int fechas_count = 0;

    for (int i = 0; i < num_orders; i++) {
        int encontrada = 0;

        // Buscar si la fecha ya está registrada
        for (int j = 0; j < fechas_count; j++) {
            if (strcmp(orders[i].order_date, fechas_unicas[j]) == 0) {
                pizzas_por_fecha[j] += orders[i].quantity;
                encontrada = 1;
                break;
            }
        }

        // Si no está registrada, la agregamos
        if (!encontrada) {
            strcpy(fechas_unicas[fechas_count], orders[i].order_date);
            pizzas_por_fecha[fechas_count] = orders[i].quantity;
            fechas_count++;
        }
    }

    // Buscar la fecha con menos pizzas
    int min_pizzas = pizzas_por_fecha[0];
    char fecha_min[20];
    strcpy(fecha_min, fechas_unicas[0]);

    for (int i = 1; i < fechas_count; i++) {
        if (pizzas_por_fecha[i] < min_pizzas) {
            min_pizzas = pizzas_por_fecha[i];
            strcpy(fecha_min, fechas_unicas[i]);
        }
    }

    printf("🍕 La fecha con MENOS pizzas vendidas es: %s con %d pizzas\n", fecha_min, min_pizzas);
}

// Función para calcular el promedio de pizzas por orden
void promedio_pizzas_por_orden(Order orders[], int num_orders) {
    int total_pizzas = 0;

    for (int i = 0; i < num_orders; i++) {
        total_pizzas += orders[i].quantity;
    }

    float promedio = (float)total_pizzas / num_orders;
    printf("El promedio de pizzas por orden es: %.2f\n", promedio);
}

// Función para calcular el promedio de pizzas por día
void promedio_pizzas_por_dia(Order orders[], int num_orders) {
    char fechas_unicas[500][20];  // Array para almacenar fechas únicas
    int pizzas_por_fecha[500] = {0};  // Para contar pizzas por fecha
    int fechas_count = 0;

    for (int i = 0; i < num_orders; i++) {
        int encontrada = 0;

        // Buscar si la fecha ya está registrada
        for (int j = 0; j < fechas_count; j++) {
            if (strcmp(orders[i].order_date, fechas_unicas[j]) == 0) {
                pizzas_por_fecha[j] += orders[i].quantity;
                encontrada = 1;
                break;
            }
        }

        // Si no está registrada, la agregamos
        if (!encontrada) {
            strcpy(fechas_unicas[fechas_count], orders[i].order_date);
            pizzas_por_fecha[fechas_count] = orders[i].quantity;
            fechas_count++;
        }
    }

    float promedio = 0;
    if (fechas_count > 0) {
        int total_pizzas = 0;
        for (int i = 0; i < fechas_count; i++) {
            total_pizzas += pizzas_por_fecha[i];
        }
        promedio = (float)total_pizzas / fechas_count;
    }

    printf("El promedio de pizzas por día es: %.2f\n", promedio);
}

// Función para encontrar el ingrediente más vendido
void ingrediente_mas_vendido(Order orders[], int num_orders) {
    char ingredientes_unicos[500][200];   // Array para almacenar los ingredientes únicos
    int cantidad_por_ingrediente[500] = {0};  // Array para contar la cantidad de veces que se vendió cada ingrediente
    int ingredientes_count = 0;  // Número de ingredientes distintos encontrados

    // Recorrer todas las órdenes y agrupar por ingredientes
    for (int i = 0; i < num_orders; i++) {
        char *ingrediente = strtok(orders[i].pizza_ingredients, ","); // Dividir la lista de ingredientes por coma
        while (ingrediente != NULL) {
            int encontrada = 0;

            // Verificar si el ingrediente ya está registrado
            for (int j = 0; j < ingredientes_count; j++) {
                if (strcmp(ingrediente, ingredientes_unicos[j]) == 0) {
                    cantidad_por_ingrediente[j]++;  // Aumentar la cantidad de ese ingrediente
                    encontrada = 1;
                    break;
                }
            }

            // Si el ingrediente no está registrado, agregarlo
            if (!encontrada) {
                strcpy(ingredientes_unicos[ingredientes_count], ingrediente);
                cantidad_por_ingrediente[ingredientes_count] = 1;  // Inicializar la cantidad en 1
                ingredientes_count++;
            }

            ingrediente = strtok(NULL, ","); // Continuar con el siguiente ingrediente
        }
    }

    // Buscar el ingrediente más vendido
    int max_cantidad = 0;
    char ingrediente_mas_vendido[200];
    for (int i = 0; i < ingredientes_count; i++) {
        if (cantidad_por_ingrediente[i] > max_cantidad) {
            max_cantidad = cantidad_por_ingrediente[i];
            strcpy(ingrediente_mas_vendido, ingredientes_unicos[i]);
        }
    }

    // Mostrar el resultado
    printf("🍴 El ingrediente más vendido es: %s con %d ventas\n", ingrediente_mas_vendido, max_cantidad);
}

// Función para contar cuántas pizzas fueron vendidas por categoría
void cantidad_pizzas_por_categoria(Order orders[], int num_orders) {
    char categorias_unicas[500][30];   // Array para almacenar las categorías únicas
    int cantidad_por_categoria[500] = {0};  // Array para contar la cantidad de pizzas vendidas por categoría
    int categorias_count = 0;  // Número de categorías distintas encontradas

    // Recorrer todas las órdenes y agrupar por categoría
    for (int i = 0; i < num_orders; i++) {
        int encontrada = 0;

        // Buscar si la categoría ya está registrada
        for (int j = 0; j < categorias_count; j++) {
            if (strcmp(orders[i].pizza_category, categorias_unicas[j]) == 0) {
                cantidad_por_categoria[j]++;  // Aumentar la cantidad de esa categoría
                encontrada = 1;
                break;
            }
        }

        // Si la categoría no está registrada, agregarla
        if (!encontrada) {
            strcpy(categorias_unicas[categorias_count], orders[i].pizza_category);
            cantidad_por_categoria[categorias_count] = 1;  // Inicializar la cantidad en 1
            categorias_count++;
        }
    }

    // Mostrar los resultados de las categorías
    printf("🍕 Cantidad de pizzas vendidas por categoría:\n");
    for (int i = 0; i < categorias_count; i++) {
        printf("Categoría %s: %d pizzas\n", categorias_unicas[i], cantidad_por_categoria[i]);
    }
}
