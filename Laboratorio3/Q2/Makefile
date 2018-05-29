
CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q2 build/main.o build/movimentacao.o build/corrente.o


bin/q2: build/main.o build/movimentacao.o build/corrente.o
	$(CC) $^ -o $@

build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/movimentacao.o : src/movimentacao.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/corrente.o : src/corrente.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

clean:
	rm build/*.o

run:
	bin/q2
