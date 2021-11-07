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

#ifndef MAZEIMG_IMAGE_NODE_H_
#define MAZEIMG_IMAGE_NODE_H_
#include <MazeImage++/utils/Vector2D.h>
#include <vector>
#include <stdint.h>
#include <string>
#include <utility>

enum NODETYPES {WALL, WHITE, ROUTE};

namespace mazeimg_library{

    class Node {
    public:

        // Constructor that accepts uint values of row, column, and total rows of the grid/board
        Node(uint32_t row, uint32_t col, uint32_t totalRows);

        // Establish connections to surrounding nodes
        void updateNeighbors(std::vector<Node*> *board); 

        // Set the attribute 'visitedNode' to true
        void setVisited();

        // Set the attribute 'route' to true
        void setRoute();

        // Set the attribute 'wall' to true
        void setWall(); 

        // Reset the state of the node
        void reset();

        // Getters
        std::vector<Node*> g_neighbors() const;
        std::pair<uint32_t, uint32_t> g_nCoord() const;
        NODETYPES g_nodeType() const;
        bool isVisited() const;
        

    private:

        std::vector<Node*> neighbors; // Neighbors of this instance in the grid/board

        uint32_t totalRows; // total number of rows in the grid/board
        uint32_t row, col;  // Row and column position of this instance in the grid/board

        NODETYPES nodeType;    // Node type - wall, white, route
        bool      visitedNode; // True if this instance was visited

    };

}

#endif // MAZEIMG_IMAGE_NODE_H_