# Maze Image Generator - MazeImage++ #
MazeImage++ is a library for C++ that allows you to generate maze images.

## External Dependencies ##
- <a href="https://imagemagick.org/script/download.php">ImageMagick</a>
- <a href="http://cimg.eu/">CImg library</a>

## Setup ##
- Run makefile to build static library.
- After the build is complete, go to the 'example' directory to test the library.
- Compile GenMaze.cpp:
```sh
g++ -std=c++17 GenMaze.cpp -L../lib -limg_maze
```