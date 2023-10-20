CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/heap.o $(OBJ)/unionFind.o
HDRS = $(INC)/heap.hpp $(INC)/unionFind.hpp
CFLAGS = -I$(INC) -pg -c

EXE = $(BIN)/pa8.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.cpp

	
$(OBJ)/unionFind.o: $(HDRS) $(SRC)/unionFind.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/unionFind.o $(SRC)/unionFind.cpp

clean:
	rm -f $(EXE) $(OBJS)
