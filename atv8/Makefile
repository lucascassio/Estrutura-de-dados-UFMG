CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Set.o
HDRS = $(INC)/Set.hpp
CFLAGS = -I$(INC) -pg -c

EXE = $(BIN)/pa10.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Set.o: $(HDRS) $(SRC)/Set.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Set.o $(SRC)/Set.cpp

clean:
	rm -f $(EXE) $(OBJS)
