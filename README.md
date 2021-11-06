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

## Generated Maze Image Samples ##
Large maze
![large_maze](https://user-images.githubusercontent.com/78135477/140598434-ccc79ae4-7ae2-4ed7-960f-463ffaf5232d.png)
<br><br>
Medium maze
![medium_maze](https://user-images.githubusercontent.com/78135477/140598446-f70316ea-e712-40c1-89ba-a8627af81369.png)
<br><br>
Small maze
![small_maze](https://user-images.githubusercontent.com/78135477/140598449-919f1be6-8f17-410d-918a-3b22ea0d9456.png)