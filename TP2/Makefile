CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/graph.o $(OBJ)/main.o $(OBJ)/ordena.o $(OBJ)/lista.o $(OBJ)/memlog.o
HDRS = $(INC)/lista.hpp $(INC)/graph.hpp $(INC)/ordena.hpp $(INC)/msgassert.hpp $(INC)/memlog.hpp
CFLAGS = -Wall -I$(INC) -pg -c -g

EXE = $(BIN)/tp2.out

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

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

all: mem perf gprof

mem: $(EXE)
	$(EXE)

perf: $(EXE)
	$(EXE)

gprof: $(EXE)
	$(EXE)
	gprof $(EXE) gmon.out > /tmp/greedy.txt

clean:
	rm -f $(EXE) $(OBJS) ./bin/gmon.out ./bin/tp2.exe
