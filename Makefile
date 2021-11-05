# Build static library

target = $(LIB)
objs := Board.o IMazeGenerator.o Node.o

CC := g++
CFLAGS := -std=c++17 -Wall

SRCPATH := src
LDIR := lib
LIB := libimg_maze.a

all: $(target) clean

$(LIB): $(objs)
	ar rsv $(LDIR)/$@ $^

Board.o: $(SRCPATH)/Board.cpp
	$(CC) $(CFLAGS) -c $<

IMazeGenerator.o: $(SRCPATH)/IMazeGenerator.cpp
	$(CC) $(CFLAGS) -c $<

Node.o: $(SRCPATH)/Node.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	del *.o