CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q2 build/main.o build/jogador.o build/jogo.o


bin/q2: build/jogo.o build/jogador.o build/main.o
	$(CC) $^ -o $@


build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/jogador.o : src/jogador.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

build/jogo.o : src/jogo.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)

clean:
	rm build/*.o

run:
	bin/q2