#include "../src/IMazeGenerator.h"

int main(){
    MazeIMG::IMazeGenerator gen_maze(M_SIZE::s);
    gen_maze.processImage("small_maze", IMG_FORMAT::PNG);

    gen_maze.setMazeSize(M_SIZE::m);
    gen_maze.processImage("medium_maze", IMG_FORMAT::PNG);

    gen_maze.setMazeSize(M_SIZE::l);
    gen_maze.processImage("large_maze", IMG_FORMAT::PNG);

    return 0;
}