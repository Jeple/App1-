#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "metrics.h"

#define MAX_LINE_LENGTH 1024

// Función para leer el archivo CSV
int read_csv(const char *filename, struct order **orders) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int size = 0;
    int capacity = 10;

    *orders = malloc(capacity * sizeof(struct order));  // Asignación inicial para 10 órdenes

    while (fgets(line, sizeof(line), file)) {
        if (size == capacity) {
            capacity *= 2;  // Aumentamos la capacidad
            *orders = realloc(*orders, capacity * sizeof(struct order));
        }

        // Dividir la línea por comas y almacenar los datos en la estructura 'order'
        char *token = strtok(line, ",");
        int field = 0;
        while (token) {
            switch (field) {
                case 0: (*orders)[size].pizza_id = atoi(token); break;
                case 1: (*orders)[size].order_id = atoi(token); break;
                case 2: strncpy((*orders)[size].pizza_name_id, token, sizeof((*orders)[size].pizza_name_id) - 1); break;
                case 3: (*orders)[size].quantity = atoi(token); break;
                case 4: strncpy((*orders)[size].order_date, token, sizeof((*orders)[size].order_date) - 1); break;
                case 5: strncpy((*orders)[size].order_time, token, sizeof((*orders)[size].order_time) - 1); break;
                case 6: (*orders)[size].unit_price = atof(token); break;
                case 7: (*orders)[size].total_price = atof(token); break;
                case 8: (*orders)[size].pizza_size = token[0]; break;
                case 9: strncpy((*orders)[size].pizza_category, token, sizeof((*orders)[size].pizza_category) - 1); break;
                case 10: strncpy((*orders)[size].pizza_ingredients, token, sizeof((*orders)[size].pizza_ingredients) - 1); break;
                case 11: strncpy((*orders)[size].pizza_name, token, sizeof((*orders)[size].pizza_name) - 1); break;
            }
            token = strtok(NULL, ",");
            field++;
        }
        size++;
    }

    fclose(file);
    return size;  // Devolvemos la cantidad de órdenes leídas
}

// Función para dividir una línea de texto en tokens por un delimitador
char *split_line(char *line, int field) {
    char *token = strtok(line, ",");
    for (int i = 0; i < field; i++) {
        token = strtok(NULL, ",");
    }
    return token;
}

// Función para liberar memoria
void free_memory(struct order *orders) {
    if (orders != NULL) {
        free(orders);
    }
}
