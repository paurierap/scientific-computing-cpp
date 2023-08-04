# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
SRC = lib/complex.cpp
INC = include/complex.h
TEST = tests/main.cpp
CFLAGS = -Wall -O

complex.o: $(SRC) $(INC)
	$(CC) $(CFLAGS) -c $(SRC)

main.o: $(TEST) $(SRC) $(INC)
	$(CC) $(CFLAGS) -c $(TEST)

test: main.o complex.o
	$(CC) $(CFLAGS) -o test complex.o main.o

clean: main.o complex.o