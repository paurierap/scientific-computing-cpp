# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
SRC = lib/matrix.cpp
INC = include/matrix.h
TEST = tests/main.cpp
CFLAGS = -Wall -O

matrix.o: $(SRC) $(INC)
	$(CC) $(CFLAGS) -c $(SRC)

main.o: $(TEST) $(SRC) $(INC)
	$(CC) $(CFLAGS) -c $(TEST)

test: main.o matrix.o
	$(CC) $(CFLAGS) -o test matrix.o main.o

clean: main.o matrix.o