// utils.c
// Funciones para leer el archivo CSV y manejar memoria dinámica

#include "utils.h"
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Elimina saltos de línea y espacios al final de un string
void trim(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r' || isspace(str[len - 1]))) {
        str[len - 1] = '\0';
        len--;
    }
}

// Función auxiliar para extraer campos incluso si están entre comillas
char *get_next_field(char **line_ptr) {
    char *start = *line_ptr;
    char *end;

    if (*start == '\"') {
        start++; // saltamos la comilla inicial
        end = strchr(start, '\"'); // buscamos la siguiente comilla
        if (end) {
            *end = '\0';
            *line_ptr = end + 2; // saltamos la comilla y la coma
        }
    } else {
        end = strchr(start, ',');
        if (end) {
            *end = '\0';
            *line_ptr = end + 1;
        } else {
            *line_ptr = start + strlen(start); // último campo
        }
    }

    return start;
}

// Lee el archivo CSV y guarda los datos en un array dinámico de 'Order'
int read_csv(const char *filename, Order **orders) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int size = 0;
    int capacity = 10;

    *orders = malloc(capacity * sizeof(Order));
    if (*orders == NULL) {
        printf("Error al asignar memoria.\n");
        fclose(file);
        return -1;
    }

    int is_header = 1;

    while (fgets(line, sizeof(line), file)) {
        trim(line);

        if (is_header) {
            is_header = 0;
            continue; // saltamos encabezado
        }

        if (size == capacity) {
            capacity *= 2;
            *orders = realloc(*orders, capacity * sizeof(Order));
            if (*orders == NULL) {
                printf("Error al reasignar memoria.\n");
                fclose(file);
                return -1;
            }
        }

        char *ptr = line;

        // Extraemos campo por campo
        (*orders)[size].pizza_id = atoi(get_next_field(&ptr));
        (*orders)[size].order_id = atoi(get_next_field(&ptr));
        strncpy((*orders)[size].pizza_name_id, get_next_field(&ptr), sizeof((*orders)[size].pizza_name_id) - 1);
        (*orders)[size].quantity = atoi(get_next_field(&ptr));
        strncpy((*orders)[size].order_date, get_next_field(&ptr), sizeof((*orders)[size].order_date) - 1);
        strncpy((*orders)[size].order_time, get_next_field(&ptr), sizeof((*orders)[size].order_time) - 1);
        (*orders)[size].unit_price = atof(get_next_field(&ptr));
        (*orders)[size].total_price = atof(get_next_field(&ptr));
        (*orders)[size].pizza_size = get_next_field(&ptr)[0];
        strncpy((*orders)[size].pizza_category, get_next_field(&ptr), sizeof((*orders)[size].pizza_category) - 1);
        strncpy((*orders)[size].pizza_ingredients, get_next_field(&ptr), sizeof((*orders)[size].pizza_ingredients) - 1);
        strncpy((*orders)[size].pizza_name, get_next_field(&ptr), sizeof((*orders)[size].pizza_name) - 1);

        size++;
    }

    fclose(file);
    return size;
}

// Libera la memoria asignada dinámicamente
void free_memory(Order *orders) {
    if (orders != NULL) {
        free(orders);
    }
}