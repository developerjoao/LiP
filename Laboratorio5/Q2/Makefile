
CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q2 build/main.o build/calculadora.o


bin/q2: build/calculadora.o build/main.o
	$(CC) $^ -o $@

build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/calculadora.o : src/calculadora.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)


clean:
	rm build/*.o

run:
	bin/q2
