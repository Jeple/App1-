# Pizzeria App - Grupo 

Integrantes: Juan Pablo Salum, Lucas Colombo, Julian Epple

Aplicación en C para analizar las ventas de una pizzería usando lectura de archivos CSV y punteros a funciones.

#Descripción
Este proyecto tiene como objetivo crear una aplicación en C para analizar las ventas de una pizzería a partir de un archivo CSV. La aplicación calcula diversas métricas relacionadas con las ventas, como la pizza más vendida, la fecha con más ventas, el ingrediente más vendido, entre otras.

#Funcionalidades
La aplicación permite calcular las siguientes métricas:

pms: Pizza más vendida.

pls: Pizza menos vendida.

dms: Fecha con más ventas en términos de dinero.

dls: Fecha con menos ventas en términos de dinero.

dmsp: Fecha con más ventas en términos de cantidad de pizzas.

dlsp: Fecha con menos ventas en términos de cantidad de pizzas.

apo: Promedio de pizzas por orden.

apd: Promedio de pizzas por día.

ims: Ingrediente más vendido.

hp: Cantidad de pizzas por categoría vendidas.

#Requisitos
Lenguaje: C (sin frameworks externos no estándar).

Compilador: gcc v5.1 o superior.

Sistema operativo: Compatible con sistemas basados en Unix (Linux, macOS) o Windows (si usas Cygwin o WSL).

#Estructura del Proyecto
El código está dividido en varios archivos para mantener una estructura modular:

main.c: Contiene la función principal y la lógica de ejecución.

metrics.c: Contiene las funciones encargadas de calcular las métricas.

utils.c: Contiene funciones auxiliares como el análisis del archivo CSV.

metrics.h: Prototipos de las funciones de métricas.

utils.h: Prototipos de funciones auxiliares.

Además, el proyecto incluye un Makefile para compilar el proyecto fácilmente.

#Uso
Para ejecutar la aplicación, usa el siguiente comando en el terminal, donde ejemplo.csv es el archivo de ventas y las métricas a calcular son las deseadas:

./app1 ejemplo.csv metrica1 metrica2 .....

Considerar que el codigo no funcionara si no se especifica al menos una metrica.


#Participantes
Integrante 1: Julian Epple.

Integrante 2: Juan Pablo Salum.

Integrante 3: Lucas Colombo.
