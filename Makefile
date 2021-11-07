# Build static library

target = $(LIB)
objs := Board.o MazeImgGenerator.o ImageProcessor.o Algorithm.o RecursiveBacktrack.o Dijkstra.o Astar.o Node.o

CC := g++
CIMGH := -Iinclude
CIMGLIB := -march=native -Dcimg_jpeg=1 -Dcimg_display=0
CFLAGS := -std=c++17 -Wall $(CIMGLIB)

SRCPATH := src
LDIR := lib
LIB := libimg_maze.a

all: $(target) clean

$(LIB): $(objs)
	ar rsv $(LDIR)/$@ $^

Board.o: $(SRCPATH)/Board.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

MazeImgGenerator.o: $(SRCPATH)/MazeImgGenerator.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

ImageProcessor.o: $(SRCPATH)/ImageProcessor.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

Algorithm.o: $(SRCPATH)/Algorithm.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

RecursiveBacktrack.o: $(SRCPATH)/RecursiveBacktrack.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

Dijkstra.o: $(SRCPATH)/Dijkstra.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

Astar.o: $(SRCPATH)/Astar.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

Node.o: $(SRCPATH)/Node.cpp
	$(CC) $(CFLAGS) $(CIMGH) -c $<

clean:
	del *.o