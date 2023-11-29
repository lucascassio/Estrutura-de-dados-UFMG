CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/arvoreSeg.o
HDRS = $(INC)/arvoreSeg.hpp
CFLAGS = -Wall -I$(INC) -pg -c -g

EXE = $(BIN)/tp3.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/arvoreSeg.o: $(HDRS) $(SRC)/arvoreSeg.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/arvoreSeg.o $(SRC)/arvoreSeg.cpp

clean:
	rm -f $(EXE) $(OBJS) ./bin/tp2.exe
