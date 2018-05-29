
CC=g++

.PHONY: all clear makefile 

INCLUDE=./include
SRC=./src
BIN=./bin
BUILD=./build


FLAGS = -Wall -pedantic -std=c++11
all: bin/q3 build/main.o


bin/q3: build/main.o
	$(CC) $^ -o $@

build/main.o : src/main.cpp
	g++ $^ -c -I include -o $@ $(FLAGS)


clean:
	rm build/*.o

run:
	bin/q3
