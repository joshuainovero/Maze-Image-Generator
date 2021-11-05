#include <iostream>
#include "IMazeGenerator.h"

int main(){
    std::srand(time(0));
    // std::ifstream checker("Shit.png");
    // assert_(checker.fail(), "File exists!");
    // Board maze;
    // for (int i = 0; i < 55; ++i){
    //     for (auto node : maze.tiles[i]){
    //         node->updateNeighbors(maze.tiles);
    //     }
    // }

    // maze.generateMaze(maze.tiles);

    // for (int i = 0; i < 55; ++i){
    //     for (int k = 0; k < 55; ++k){
    //         if (maze.board[i][k]->visitedMaze == false){
    //             maze.mazePath[i].push_back(maze.board[i][k]);
    //         }
    //     }
    // }

    // for (int i = 0; i < 55; ++i){
    //     for (auto node : maze.tiles[i]){
    //         if (node->visitedMaze == false){
    //             node->setObstruction();
    //         }
    //     }
    // }

    // for (int i = 0; i < 55; ++i){
    //     for (auto node : maze.board[i]){
    //         node->updateNeighbors(maze.board);
    //     }
    // }


    // for (int i = 0; i < 55; ++i){
    //     for (auto node : maze.board[i]){
    //         if (node->nodeType == "wall")
    //             std::cout << "0 ";
    //         else if (node->nodeType == "white")
    //             std::cout << "1 ";
    //     }
    //     std::cout << std::endl;
    // }
    

    // std::ofstream image("image.ppm");



    // image << "P3" << std::endl << "55 55" << std::endl << "255" << std::endl;

    // for (int i = 0; i < 55; ++i){
    //     for (int k = 0; k < 55; ++k){
    //         if (maze.board[i][k]->nodeType == "wall")
    //             image << "0 0 0" << std::endl;
    //         else if (maze.board[i][k]->nodeType == "white")
    //             image << "255 255 255" << std::endl;
    //     }

    //         // std::cout << "(" << node->row << ", " << node->col << ") ";
    //     // std::cout << std::endl;
    // }

    // image.close();

    // std::vector<int> imageVec[1100];

    // for (int i = 0; i < 1100; ++i){
    //     for (int k = 0; k < 1100; ++k){
    //         imageVec[i].push_back(1); 
    //     }
    // }

    // int xcounter = 0;
    // int ycounter = 0;
    // for (int y = 0; y < 55; ++y){
    //     for (int x = 0; x < 55; ++x){
    //         int wallType;
    //         if (maze.board[y][x]->nodeType == "wall")
    //             wallType = 0;
    //         else if (maze.board[y][x]->nodeType == "white")
    //             wallType = 1;

    //         for (int i = 0; i < 20; ++i){
    //             for (int b = 0; b < 20; ++b){
    //                 imageVec[ycounter + b][xcounter] = wallType;
    //             }
    //             imageVec[ycounter][xcounter] = wallType;
    //             xcounter++;
    //         }
    //     }
    //     xcounter = 0;
    //     y = y + 20;
    // }
    // for (int i = 0; i < 55; ++i){
    //     for (int k = 0; k < 55; ++k){
    //         if (maze.board[i][k]->nodeType == "wall"){
    //             for (int f = 0; f < 20; ++f){
    //                 for (int b = 0; b < 20; ++b){
    //                     imageVec[ycounter + b][xcounter] = 0;
    //                 }
    //                 xcounter++;
    //             }
    //         }
    //         else if (maze.board[i][k]->nodeType == "white"){
    //             for (int f = 0; f < 20; ++f){
    //                 for (int b = 0; b < 20; ++b){
    //                     imageVec[ycounter + b][xcounter] = 1;
    //                 }
    //                 xcounter++;
    //             }
    //         }
    //     }
    //     xcounter = 0;
    //     ycounter += 20;

    // }

    // for (int i = 0; i < 55; ++i){
    //     for (int k = 0; k < 55; ++k){
    //         int wallType;
    //         if (maze.tiles[i][k]->nodeType == "wall"){
    //             wallType = 0;
    //         }
    //         else if (maze.tiles[i][k]->nodeType == "white"){
    //             wallType = 1;
    //         }
    //         for (int f = 0; f < 20; ++f){
    //             for (int b = 0; b < 20; ++b){
    //                 imageVec[ycounter + b][xcounter] = wallType;
    //             }
    //             xcounter++;
    //         }
    //     }
    //     xcounter = 0;
    //     ycounter += 20;

    // }
    // std::ofstream image("image.ppm");



    // image << "P3" << std::endl << "1100 1100" << std::endl << "255" << std::endl;

    // for (int i = 0; i < 1100; ++i){
    //     for (int k = 0; k < 1100; ++k){
    //         if (imageVec[i][k] == 0)
    //            image << "0 0 0" << std::endl;
    //         else if (imageVec[i][k] == 1)
    //              image << "255 255 255" << std::endl;
    //     }
    // }

    // image.close();


    MazeIMG::IMazeGenerator gen_maze(M_SIZE::s);
    gen_maze.processImage("small_maze", IMG_FORMAT::PNG);

    // gen_maze.setMazeSize(M_SIZE::m);
    gen_maze.processImage("medium_maze", IMG_FORMAT::PNG);

    // gen_maze.setMazeSize(M_SIZE::l);
    gen_maze.processImage("large_maze", IMG_FORMAT::PNG);


}