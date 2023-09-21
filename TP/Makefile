CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/expop.o $(OBJ)/exp.o
HDRS = $(INC)/exp.h
CFLAGS = -Wall -I$(INC) -pg -c -g

EXE = $(BIN)/tp1.exe

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/expop.o: $(HDRS) $(SRC)/expop.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/expop.o $(SRC)/expop.cpp

$(OBJ)/exp.o: $(HDRS) $(SRC)/exp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/exp.o $(SRC)/exp.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
