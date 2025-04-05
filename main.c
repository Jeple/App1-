/**
 * main.c - Programa principal para análisis de ventas de pizzas desde CSV
 * 
 * Este programa permite leer un archivo CSV de ventas de pizzas y calcular
 * diferentes métricas especificadas como parámetros en la línea de comandos.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>
 #include "metrics.h"
 #include "utils.h"
 
 /**
  * Muestra la forma correcta de uso del programa
  */
 void print_usage(const char* program_name) {
     printf("Uso: %s <archivo_csv> <métrica1> [<métrica2> ...]\n", program_name);
     printf("Métricas disponibles:\n");
     printf("  pms      - Pizza más vendida\n");
     printf("  pls      - Pizza menos vendida\n");
     printf("  dms      - Fecha con más ventas (en dinero)\n");
     printf("  dls      - Fecha con menos ventas (en dinero)\n");
     printf("  dmsp     - Fecha con más pizzas vendidas (cantidad)\n");
     printf("  dlsp     - Fecha con menos pizzas vendidas\n");
     printf("  apo      - Promedio de pizzas por orden\n");
     printf("  apd      - Promedio de pizzas por día\n");
     printf("  ims      - Ingrediente más vendido\n");
     printf("  hp       - Cantidad de pizzas vendidas por categoría\n");
     printf("\nEjemplo: %s ventas.csv pms dms apo\n", program_name);
 }
 
 /**
  * Ejecuta la métrica especificada sobre el conjunto de órdenes
  * @param metric_name Nombre de la métrica a ejecutar
  * @param orders Arreglo de órdenes
  * @param num_orders Número de órdenes
  * @return true si la métrica es válida, false en caso contrario
  */
 bool execute_metric(const char* metric_name, Order orders[], int num_orders) {
     if (strcmp(metric_name, "pms") == 0) {
         pizza_mas_vendida(orders, num_orders);
     } else if (strcmp(metric_name, "pls") == 0) {
         pizza_menos_vendida(orders, num_orders);
     } else if (strcmp(metric_name, "dms") == 0) {
         fecha_mas_ventas(orders, num_orders);
     } else if (strcmp(metric_name, "dls") == 0) {
         fecha_menor_ventas(orders, num_orders);
     } else if (strcmp(metric_name, "dmsp") == 0) {
         fecha_mas_pizzas(orders, num_orders);
     } else if (strcmp(metric_name, "dlsp") == 0) {
         fecha_menos_pizzas(orders, num_orders);
     } else if (strcmp(metric_name, "apo") == 0) {
         promedio_pizzas_por_orden(orders, num_orders);
     } else if (strcmp(metric_name, "apd") == 0) {
         promedio_pizzas_por_dia(orders, num_orders);
     } else if (strcmp(metric_name, "ims") == 0) {
         ingrediente_mas_vendido(orders, num_orders);
     } else if (strcmp(metric_name, "hp") == 0) {
         cantidad_pizzas_por_categoria(orders, num_orders);
     } else {
         return false;
     }
     return true;
 }
 
 /**
  * Función principal que procesa el archivo CSV y calcula las métricas solicitadas
  */
 int main(int argc, char* argv[]) {
     // Verificar que haya suficientes argumentos
     if (argc < 3) {
         print_usage(argv[0]);
         return EXIT_FAILURE;
     }
     
     // Obtener el nombre del archivo
     const char* filename = argv[1];
     
     // Cargar los datos del archivo CSV
     Order* orders = NULL;
     int num_orders = read_csv(filename, &orders);
     
     if (num_orders <= 0) {
         fprintf(stderr, "Error: No se pudieron cargar datos del archivo %s\n", filename);
         return EXIT_FAILURE;
     }
     
     printf("Se cargaron %d órdenes del archivo %s\n", num_orders, filename);
     printf("-----------------------------------------------------\n");
     
     // Procesar cada métrica solicitada
     bool all_metrics_valid = true;
     for (int i = 2; i < argc; i++) {
         const char* metric_name = argv[i];
         
         printf("\n[MÉTRICA: %s]\n", metric_name);
         if (!execute_metric(metric_name, orders, num_orders)) {
             fprintf(stderr, "Error: Métrica desconocida '%s'\n", metric_name);
             all_metrics_valid = false;
         }
         printf("\n");
     }
     
     // Liberar la memoria
     free_memory(orders);
     
     return all_metrics_valid ? EXIT_SUCCESS : EXIT_FAILURE;
 }
