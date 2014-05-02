.PHONY= clean

CC = g++
CFLAGS = -g -std=gnu++0x

LIBDIR = lib
BUILDIR = build
INCLUDEDIR = include
SRCDIR = src

TARGET = bin/benchmark

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

_OBJ= QuadLinkedTrieNode.o QuadLinkedTrie.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

all: $(TARGET)

$(TARGET): $(SOURCES) $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) $(SOURCES) $(OBJ) -o $(TARGET)

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(CFLAGS) -c -I$(INCLUDEDIR) -o $@ $<

clean:
	rm -f $(OBJ) 
