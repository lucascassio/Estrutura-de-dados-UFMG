CC = gcc
CFLAGS = -std=c11 -Wall
SRC = src
OBJ = obj
BIN = bin
INC = include
OBJS = $(OBJ)/testeFatIterativo.o $(OBJ)/testeFibIterativo.o $(OBJ)/testeFatRecursivo.o $(OBJ)/testeFibRecursivo.o
EXE = $(BIN)/testeFatIterativo $(BIN)/testeFatRecursivo $(BIN)/testeFibIterativo $(BIN)/testeFibRecursivo

MAIN_SOURCE = $(SRC)/testes.c
CONTRACT_SOURCE = $(SRC)/testesop.c

EXECUTABLE = $(BIN)/main

ARGUMENT = 20

all: $(EXECUTABLE)

$(EXECUTABLE): $(MAIN_SOURCE) $(CONTRACT_SOURCE)
	$(CC) $(CFLAGS) -I$(INC) -o $@ $^
	@echo "Compilado: $@"

run: $(EXECUTABLE)
	@echo "Executando programa com argumento: $(ARGUMENT)"
	@./$(EXECUTABLE) $(ARGUMENT)

clean:
	rm -f $(EXECUTABLE) $(OBJS) $(EXE)

.PHONY: all clean run analyze
