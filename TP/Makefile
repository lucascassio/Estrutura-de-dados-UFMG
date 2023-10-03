CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/expop.o $(OBJ)/exp.o $(OBJ)/pilhaEncadeada.o $(OBJ)/arvoreBinaria.o
HDRS = $(INC)/exp.h $(INC)/pilhaEncadeada.h $(INC)/arvoreBinaria.h
CFLAGS = -Wall -I$(INC) -pg -c -g

EXE = $(BIN)/tp1.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/expop.o: $(HDRS) $(SRC)/expop.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/expop.o $(SRC)/expop.cpp

$(OBJ)/exp.o: $(HDRS) $(SRC)/exp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/exp.o $(SRC)/exp.cpp

$(OBJ)/pilhaEncadeada.o: $(HDRS) $(SRC)/pilhaEncadeada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilhaEncadeada.o $(SRC)/pilhaEncadeada.cpp

$(OBJ)/arvoreBinaria.o: $(HDRS) $(SRC)/arvoreBinaria.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/arvoreBinaria.o $(SRC)/arvoreBinaria.cpp

clean:
	rm -f $(EXE) $(OBJS) ./bin/gmon.out ./bin/tp1.exe
