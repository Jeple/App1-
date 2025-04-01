CC = gcc                          # Definimos el compilador a usar (gcc: GNU Compiler Collection)
CFLAGS = -Wall -g                # Opciones para el compilador:
                                # -Wall: muestra todos los warnings (buenas prácticas)
                                # -g: incluye información de depuración para usar con herramientas como gdb

OBJ = main.o utils.o metrics.o   # Lista de archivos objeto que se generan al compilar los .c
EXEC = app                       # Nombre del ejecutable final

all: $(EXEC)                    # Regla por defecto: si ejecutas "make" se va a construir el ejecutable

$(EXEC): $(OBJ)                 # Para construir el ejecutable, necesitamos los archivos objeto primero
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)   # Compila y enlaza todos los .o en un solo ejecutable llamado "app"

main.o: main.c utils.h metrics.h     # main.o depende de estos archivos
	$(CC) $(CFLAGS) -c main.c         # Compila main.c en main.o

utils.o: utils.c utils.h metrics.h   # utils.o depende de utils y metrics
	$(CC) $(CFLAGS) -c utils.c        # Compila utils.c en utils.o

metrics.o: metrics.c metrics.h       # metrics.o depende de metrics.h
	$(CC) $(CFLAGS) -c metrics.c      # Compila metrics.c en metrics.o

clean:                             # Comando para limpiar la carpeta (borrar archivos intermedios)
	rm -f $(OBJ) $(EXEC)            # Elimina los .o y el ejecutable "app"
