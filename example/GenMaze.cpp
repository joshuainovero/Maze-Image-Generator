#include <MazeImage++/MazeImage++.h>

int main(void){
    mazeimg_library::MazeImgGenerator gen_maze(M_SIZE::s);

    // enable solution - display shortest path
    gen_maze.enableSolution(true);

    // Small maze
    gen_maze.generate("small_maze", IMG_FORMAT::PNG);

    // Medium maze
    gen_maze.setMazeSize(M_SIZE::m);
    gen_maze.generate("medium_maze", IMG_FORMAT::PNG);

    // Large maze
    gen_maze.setMazeSize(M_SIZE::l);
    gen_maze.generate("large_maze", IMG_FORMAT::PNG);

    return 0;
}