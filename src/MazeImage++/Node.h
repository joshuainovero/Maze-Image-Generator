/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Node.h
 * This file is used to initialize objects of nodes in the maze
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

#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <stdint.h>
#include <string>
#include <utility>

namespace mazeimg_library{

    class Node {
    public:

        // Constructor that accepts uint values of row, column, and total rows of the grid/board
        Node(uint32_t row, uint32_t col, uint32_t totalRows);

        // Establish connections to surrounding nodes
        void updateNeighbors(std::vector<Node*> *board); 

        // Set the attribute 'visitedNode' to true
        void setVisited();

        // Reset the state of the node
        void reset();

        // Getters for attributes: neighbors, visitedNode, row, and column
        std::vector<Node*> g_neighbors() const;
        std::pair<uint32_t, uint32_t> g_nCoord() const;
        bool isVisited() const;

    private:

        std::vector<Node*> neighbors; // Neighbors of this instance in the grid/board

        uint32_t totalRows; // total number of rows in the grid/board
        uint32_t row, col;  // Row and column position of this instance in the grid/board

        bool visitedNode; // True if this instance was visited during recursive backtrack
        bool wall;        // True if if this instance is a wall node

    };

}

#endif // NODE_H_