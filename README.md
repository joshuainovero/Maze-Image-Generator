# Maze Image Generator - MazeImage++ #
MazeImage++ is a library for C++ that allows you to generate maze images.

## External Dependencies ##
- <a href="https://imagemagick.org/script/download.php">ImageMagick</a>
- <a href="http://cimg.eu/">CImg library</a>

## Supported Image Formats ##
- JPG
- PNG

## Setup ##
- For linux:
```sh
sudo apt install libx11-dev
sudo apt install imagemagick
```
- Run CMake
- Go to build directory and run makefile to build static library.
- After the build is complete, go to the 'example' directory to test the library.
- Compile GenMaze.cpp:
```sh
g++ -std=c++17 -I../include GenMaze.cpp -L../lib -limg_maze
```

## Generated Maze Image Samples ##
# Mazes without solution #
Large maze
![large_maze](https://user-images.githubusercontent.com/78135477/140655627-f7d3e1de-aca5-4fd6-9789-aee5d357d915.png)
<br><br>
Medium maze
![medium_maze](https://user-images.githubusercontent.com/78135477/140655634-c13e53e5-8608-4347-ba8c-dbe8b44749d4.png)
<br><br>
Small maze
![small_maze](https://user-images.githubusercontent.com/78135477/140655648-ada21a7d-ba15-47a8-82dc-23060a49fb98.png)

# Mazes with solution #
Large maze with solution
![large_maze_solution](https://user-images.githubusercontent.com/78135477/140655652-2d18ce0f-797b-4456-8aa0-3d0de5ddf0e9.png)
Medium maze with solution
![medium_maze_solution](https://user-images.githubusercontent.com/78135477/140655660-2694a69b-dcc1-483d-8663-0b27fee01757.png)
Small maze with solution
![small_maze_solution](https://user-images.githubusercontent.com/78135477/140655668-7e610ed4-5f51-44ac-b97a-d3e153f49232.png)