CC = gcc
CFLAGS = -Wall

# Arquivos objetos
OBJ = main.o busca.o

# Nome do executável
EXEC = main

# Regra para compilar o programa
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regra para compilar main.c
main.o: main.c lib.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar busca.c
busca.o: busca.c lib.h
	$(CC) $(CFLAGS) -c busca.c

# Limpeza dos arquivos objetos e executáveis
clean:
	rm -f $(OBJ) $(EXEC)
