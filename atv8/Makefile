CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/avl.o
HDRS = $(INC)/avl.hpp
CFLAGS = -I$(INC) -pg -c

EXE = $(BIN)/pa11.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/avl.o: $(HDRS) $(SRC)/avl.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avl.o $(SRC)/avl.cpp

clean:
	rm -f $(EXE) $(OBJS)
