CC = gcc
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/testesop.o $(OBJ)/testes.o
HDRS = $(INC)/testes.h
CFLAGS = -Wall -I$(INC) -pg -c -g

EXE = $(BIN)/testes

run:  $(EXE)
	$(EXE) 5

$(BIN)/testes: $(OBJS)
	$(CC) -pg -o $(BIN)/testes $(OBJS) $(LIBS)


$(OBJ)/testesop.o: $(HDRS) $(SRC)/testesop.c
	$(CC) $(CFLAGS) -o $(OBJ)/testesop.o $(SRC)/testesop.c 

$(OBJ)/testes.o: $(HDRS) $(SRC)/testes.c
	$(CC) $(CFLAGS) -o $(OBJ)/testes.o $(SRC)/testes.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out