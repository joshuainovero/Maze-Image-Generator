/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Algorithm.h
 * Abstract class for child algorithm classes
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

#ifndef MAZEIMG_IMAGE_ALGORITHM_H
#define MAZEIMG_IMAGE_ALGORITHM_H
#include <MazeImage++/utils/Node.h>
#include <algorithm>
#include <cmath>

namespace mazeimg_library{

    class Algorithm{
    public:

        // Constructor
        Algorithm(std::vector<Node*> *tiles_, uint32_t totalRows_);

        // Destructor
        virtual ~Algorithm() = 0;

        // Pure virtual function - derived classes will implement this to run their algorithm
        virtual std::vector<Node*>* run() = 0;

    protected:
    
        std::vector<Node*> *tiles; // All the node instances of the grid/board

        uint32_t totalRows; // total number of rows in the grid/board

        // Updates the neighbors of all nodes
        void updateTileNeighbors();

    };

}

#endif // MAZEIMG_IMAGE_ALGORITHM_H