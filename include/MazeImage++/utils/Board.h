/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Board.h
 * This file is used to initialize the graph and implement the maze algorithm
 * 
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the LICENSE file.
 * 
 * The origin of this software must not be misrepresented;
 * you must not claim that you wrote the original software.
 * If you use this software in a product, an acknowledgment
 * in the product documentation would be appreciated but is not required.
 * 
 *****************************************************************************/

#ifndef MAZEIMG_IMAGE_BOARD_H_
#define MAZEIMG_IMAGE_BOARD_H_
#include <MazeImage++/utils/Node.h>
#include <MazeImage++/utils/CLIOutput.h>
#include <MazeImage++/utils/Algorithm.h>
#include <MazeImage++/utils/RecursiveBacktrack.h>
#include <MazeImage++/utils/Dijkstra.h>
#include <MazeImage++/utils/Astar.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

// User defined data type to specify the size of the maze
// s (small size)  - 25 rows in the grid/board and 44 pixels for each block
// m (medium size) - 55 rows in the grid/board and 20 pixels for each block
// l (large size)  - 275 rows in the grid/board and 4 pixels for each block 
enum M_SIZE      {s = 44, m = 20, l = 4};

enum SEARCHALGOS {DIJKSTRA, ASTAR};

namespace mazeimg_library{

    class Board {
    public:

        inline static const uint32_t img_SIZE = 1100; // Generated image size is always 1100 x 1100

        // Constructor with immediate maze size specification
        Board(M_SIZE m_size);

        // Calls deallocaterBoard()
        ~Board();

        Algorithm* mazeAlgo;
        std::vector<Algorithm*> searchAlgorithms;
        Algorithm* currentAlgorithm;

        // Allocates new size of board
        void constructBoard(M_SIZE m_size);

        // Deallocates tiles object as well as Node* pointers 
        void deallocateBoard();
        
        // Getters for attributes: totalRows, m_size
        uint32_t g_totalRows() const;
        M_SIZE g_m_size() const;

    private:

        std::vector<Node*> *tiles;    // All the node instances of the grid/board

        uint32_t totalRows; // total number of rows in the grid/board
        M_SIZE   m_size;    // Size of one block/tile of a node
        
    };  
    
}
#endif // MAZEIMG_IMAGE_BOARD_H_