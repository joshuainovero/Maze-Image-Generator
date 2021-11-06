# Build static library

target = $(LIB)
objs := Board.o MazeImgGenerator.o Node.o

CC := g++
CIMGLIB := -march=native -Dcimg_jpeg=1 -Dcimg_display=0
CFLAGS := -std=c++17 -Wall $(CIMGLIB)

SRCPATH := src/MazeImage++
LDIR := lib
LIB := libimg_maze.a

all: $(target) clean

$(LIB): $(objs)
	ar rsv $(LDIR)/$@ $^

Board.o: $(SRCPATH)/Board.cpp
	$(CC) $(CFLAGS) -c $<

MazeImgGenerator.o: $(SRCPATH)/MazeImgGenerator.cpp
	$(CC) $(CFLAGS) -c $<

Node.o: $(SRCPATH)/Node.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	del *.o