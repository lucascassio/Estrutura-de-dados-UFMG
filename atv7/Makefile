# Makefile para compilar evalenum.c

# Nome do executável
TARGET = bin/pa9.out

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c11

# Diretórios
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Lista de objetos necessários para a compilação
OBJS = $(OBJDIR)/evalenum.o

# Regra padrão para a construção do executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para a compilação do arquivo fonte
$(OBJDIR)/evalenum.o: $(SRCDIR)/evalenum.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos objetos e o executável
clean:
	rm -f $(OBJS) $(TARGET)
