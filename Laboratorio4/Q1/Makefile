
CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q1 build/main.o  build/palindromo.o


bin/q1: build/main.o build/palindromo.o
	$(CC) $^ -o $@

build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/palindromo.o : src/palindromo.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

clean:
	rm build/*.o

run:
	bin/q1
