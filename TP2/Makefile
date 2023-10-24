CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/graph.o $(OBJ)/main.o $(OBJ)/ordena.o $(OBJ)/lista.o
HDRS = $(INC)/lista.hpp $(INC)/graph.hpp $(INC)/ordena.hpp
CFLAGS = -Wall -I$(INC) -pg -c -g

EXE = $(BIN)/tp2.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/lista.o: $(HDRS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp

$(OBJ)/ordena.o: $(HDRS) $(SRC)/ordena.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ordena.o $(SRC)/ordena.cpp

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

clean:
	rm -f $(EXE) $(OBJS) ./bin/gmon.out ./bin/tp2.exe
