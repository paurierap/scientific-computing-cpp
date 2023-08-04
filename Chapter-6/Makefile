# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -O
 
complex.o: lib/complex.cpp include/complex.h
		$(CC) $(CFLAGS) lib/complex.cpp

main.o: tests/main.cpp include/complex.h
		$(CC) $(CFLAGS) tests/main.cpp

main: main.o complex.o
		$(CC) $(CFLAGS) main complex.o main.o