
CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q1 build/main.o  build/produto.o build/fruta.o build/roupa.o build/bebida.o


bin/q1: build/main.o build/produto.o build/fruta.o build/roupa.o build/bebida.o 
	$(CC) $^ -o $@

build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/produto.o : src/produto.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/fruta.o : src/fruta.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/roupa.o : src/roupa.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/bebida.o : src/bebida.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

clean:
	rm build/*.o

run:
	bin/q1
