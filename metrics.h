/*Prototipos Funciones de Calculo (Metricas), header*/

#ifndef METRICS_H
#define METRICS_H
#include "utils.h" 

// Definir la estructura order
struct order {
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
};

// Declarar las funciones
int read_csv(const char *filename, struct order **orders);
char *split_line(char *line, int field);
void free_memory(struct order *orders);

#endif // METRICS_H
