/*Funciones auxiliares, lectura de CSV*/
#include <stdio.h> //Libreria estandar para input/output (prinf, fopen, etc)
#include <stdlib.h> //Libreria para funciones generales (exit, malloc, etc)
include <string.h> //Para funciones con strigs (como strcpy, strtok, etc)
#include "utils.h" //Header propio donde estara el prototipo de la funcion
//Funcion que lee y muestra el contenido del archivo csv
void leerArchivosCSV(const char* nombreArchivo ){
    FILE* archivo = fopen(nombreArchivo, "r"); //Abre el archivo en modo lectura ("r")
    if (archivo == NULL){ //Verifica si hubo error al abrir
    printf("Error al abrir el archivo: %s\n");
    return;
    }
    char lineal[1024]; //Buffer para almacenar cada linea del archivo
    printf("Leyendo archivo: %s\n", nombreArchivo);
    while(fgets(linea,sizeof(linea),archivo)){ //Lee linea por linea hasta End of File
        printf("%s",linea); //Muestra cada linea por la consola
    }
    fclose(archivo); //Le da el cierre al archivo
}