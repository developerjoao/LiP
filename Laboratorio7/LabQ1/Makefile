
CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q1 build/main.o build/funcionario.o build/empresa.o


bin/q1: build/funcionario.o build/empresa.o build/main.o
	$(CC) $^ -o $@


build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/funcionario.o : src/funcionario.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/empresa.o : src/empresa.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)



clean:
	rm build/*.o

run:
	bin/q1
