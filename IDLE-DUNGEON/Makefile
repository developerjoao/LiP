BINDIR = ./bin
SRCDIR = ./src
INCLUDEDIR = ./include
APPDIR = ./application
OBJDIR = ./build
TESTDIR = ./test
LIBDIR = ./lib

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -I $(INCLUDEDIR)
LDFLAGS =
ARCHIVE = ar

BIN = ${BINDIR}/main
APP = ${APPDIR}/main.cpp

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.cpp,$(OBJDIR)/%.o,$(APP))

_TESTS = $(wildcard $(TESTDIR)/*.cpp)
TESTS = $(patsubst %.cpp,%,$(_TESTS))

$(BIN): $(OBJS) $(APPOBJ)
	$(CC) -o $(BIN) $(APPOBJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)

${OBJDIR}/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

minhalib.a: $(SRCDIR)/character.cpp $(SRCDIR)/func.cpp $(SRCDIR)/equips.cpp $(SRCDIR)/monster.cpp $(SRCDIR)/thief.cpp $(SRCDIR)/warlock.cpp $(SRCDIR)/warrior.cpp $(INCLUDEDIR)/character.h $(INCLUDEDIR)/func.h $(INCLUDEDIR)/equips.h $(INCLUDEDIR)/monster.h $(INCLUDEDIR)/thief.h $(INCLUDEDIR)/warlock.h $(INCLUDEDIR)/warrior.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/character.cpp -o $(OBJDIR)/character.o
	$(CC) $(CFLAGS) -c $(SRCDIR)/func.cpp -o $(OBJDIR)/func.o
	$(CC) $(CFLAGS) -c $(SRCDIR)/equips.cpp -o $(OBJDIR)/equips.o
	$(CC) $(CFLAGS) -c $(SRCDIR)/monster.cpp -o $(OBJDIR)/monster.o
	$(CC) $(CFLAGS) -c $(SRCDIR)/thief.cpp -o $(OBJDIR)/thief.o
	$(CC) $(CFLAGS) -c $(SRCDIR)/warlock.cpp -o $(OBJDIR)/warlock.o
	$(CC) $(CFLAGS) -c $(SRCDIR)/warrior.cpp -o $(OBJDIR)/warrior.o
	$(ARCHIVE) rcs $(LIBDIR)/$@ $(OBJDIR)/character.o $(OBJDIR)/func.o $(OBJDIR)/equips.o $(OBJDIR)/monster.o $(OBJDIR)/thief.o $(OBJDIR)/warlock.o $(OBJDIR)/warrior.o
	@echo "Biblioteca estática criada em $(LIBDIR)/$@"

prog_estatico:
	$(CC) $(CFLAGS) $(APPDIR)/main.cpp $(LIBDIR)/minhalib.a -o $(OBJDIR)/$@

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
	$(CC) $(CFLAGS) $(APPDIR)/main.cpp $(LIBDIR)/minhalib.so -o $(OBJDIR)/$@

test: $(TESTS) 
	$(info ************  Testes concluídos com sucesso! ************)

$(TESTDIR)/t_%: $(TESTDIR)/t_%.cpp $(OBJS)
	$(CC) -o $@ $< $(OBJS) $(CFLAGS) $(LDFLAGS)
	$@
run:
	$(BINDIR)/main
all:
	make
	$(BINDIR)/main
clean:
	rm -f $(BINDIR)/* $(OBJDIR)/* $(APPOBJ)/* $(LIBDIR)/*
	rm -f $(TESTDIR)/*
re:
	make clean
	make