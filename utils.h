// utils.h
// Prototipos y estructura para manejar lectura del archivo CSV

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Representa una orden de pizza, tal como viene en el archivo ventas.csv
typedef struct order {
    int pizza_id;
    int order_id;
    char pizza_name_id[100];
    int quantity;
    char order_date[20];
    char order_time[10];
    float unit_price;
    float total_price;
    char pizza_size;
    char pizza_category[50];
    char pizza_ingredients[200];
    char pizza_name[100];
} Order;

// Lee el archivo CSV y carga las órdenes en memoria dinámica
int read_csv(const char *filename, Order **orders);

// Libera la memoria del array de órdenes creado con read_csv
void free_memory(Order *orders);

#endif // UTILS_H