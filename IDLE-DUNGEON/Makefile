BINDIR = ./bin
SRCDIR = ./src
INCLUDEDIR = ./include
APPDIR = ./application
OBJDIR = ./build
TESTDIR = ./test
LIBDIR = ./lib

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -I $(INCLUDEDIR)
ARCHIVE = ar

BIN = ${BINDIR}/main
APP = ${APPDIR}/main.cpp

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.cpp,$(OBJDIR)/%.o,$(APP))

$(BIN): $(OBJS) $(APPOBJ)
	$(CC) -o $(BIN) $(APPOBJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)

${OBJDIR}/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

minhalib.so: $(SRCDIR)/character.cpp $(SRCDIR)/func.cpp $(SRCDIR)/equips.cpp $(SRCDIR)/monster.cpp $(SRCDIR)/thief.cpp $(SRCDIR)/warlock.cpp $(SRCDIR)/warrior.cpp $(INCLUDEDIR)/character.h $(INCLUDEDIR)/func.h $(INCLUDEDIR)/equips.h $(INCLUDEDIR)/monster.h $(INCLUDEDIR)/thief.h $(INCLUDEDIR)/warlock.h $(INCLUDEDIR)/warrior.h
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/character.cpp -o $(OBJDIR)/character.o
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/func.cpp -o $(OBJDIR)/func.o
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/equips.cpp -o $(OBJDIR)/equips.o
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/monster.cpp -o $(OBJDIR)/monster.o
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/thief.cpp -o $(OBJDIR)/thief.o
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/warlock.cpp -o $(OBJDIR)/warlock.o
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/warrior.cpp -o $(OBJDIR)/warrior.o
	$(CC) -shared -fPIC -o $(LIBDIR)/$@ $(OBJDIR)/character.o $(OBJDIR)/func.o $(OBJDIR)/equips.o $(OBJDIR)/monster.o $(OBJDIR)/thief.o $(OBJDIR)/warlock.o $(OBJDIR)/warrior.o
	@echo "Biblioteca dinâmica criada em $(LIBDIR)/$@"

prog_dinamico:
	$(CC) $(CFLAGS) $(APPDIR)/main.cpp $(LIBDIR)/minhalib.so -o $(BINDIR)/$@

run:
	$(BINDIR)/prog_dinamico
all:
	make minhalib.so
	make prog_dinamico 
	make run
clean:
	rm -f $(BINDIR)/* $(OBJDIR)/* $(APPOBJ)/*
	rm -f $(TESTDIR)/*
re:
	make clean
	make