#include "funciones.h"

float calcular_total(int datos[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) total += datos[i];
    return total;
}

float calcular_promedio(int datos[], int n) {
    return calcular_total(datos, n) / n;
}

int valor_maximo(int datos[], int n) {
    int max = datos[0];
    for (int i = 1; i < n; i++) if (datos[i] > max) max = datos[i];
    return max;
}

int valor_minimo(int datos[], int n) {
    int min = datos[0];
    for (int i = 1;
