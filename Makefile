# Makefile para la aplicación de análisis de ventas de pizzas

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Nombre del ejecutable
TARGET = app1

# Archivos fuente
SOURCES = main.c utils.c metrics.c
# Objetos no necesarios, compilamos todo en un solo paso

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Compilación completada. Ejecutar con: ./$(TARGET) ventas.csv <métrica1> [<métrica2> ...]"

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET)
	@echo "Limpieza completada"

# Regla para ejecutar la aplicación (ejemplo con algunas métricas)
run: $(TARGET)
	./$(TARGET) ventas.csv pms dms apo

# Regla para mostrar ayuda
help:
	@echo "Uso del Makefile:"
	@echo "  make       - Compila la aplicación ($(TARGET))"
	@echo "  make clean - Elimina los archivos generados"
	@echo "  make run   - Ejecuta la aplicación con un ejemplo"
	@echo "  make help  - Muestra esta ayuda"
	@echo ""
	@echo "Para ejecutar con métricas específicas:"
	@echo "  ./$(TARGET) ejemplo.csv <métrica1> [<métrica2> ...]"
	@echo ""
	@echo "Métricas disponibles:"
	@echo "  pms  - Pizza más vendida"
	@echo "  pls  - Pizza menos vendida"
	@echo "  dms  - Fecha con más ventas (en dinero)"
	@echo "  dls  - Fecha con menos ventas (en dinero)"
	@echo "  dmsp - Fecha con más pizzas vendidas (cantidad)"
	@echo "  dlsp - Fecha con menos pizzas vendidas (cantidad)"
	@echo "  apo  - Promedio de pizzas por orden"
	@echo "  apd  - Promedio de pizzas por día"
	@echo "  ims  - Ingrediente más vendido"
	@echo "  hp   - Cantidad de pizzas vendidas por categoría"

# Indica que estos objetivos no son archivos
.PHONY: all clean run help
