/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: RecursiveBacktrack.h
 * Derived class of Algorithm.h
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

#ifndef MAZEIMG_IMAGE_RECURSIVEBACKTRACK_H
#define MAZEIMG_IMAGE_RECURSIVEBACKTRACK_H
#include <MazeImage++/utils/Algorithm.h>

namespace mazeimg_library{

    class RecursiveBacktrack : public Algorithm{
    public:

        // Constructor copies tiles and totalRows
        RecursiveBacktrack(std::vector<Node*> *tiles_, uint32_t totalRows_);

        // Destructor
        virtual ~RecursiveBacktrack() override;
        
        // Function to run recursive backtracking algorithm
        virtual std::vector<Node*>* run() override;

        // DFS helper for recursive backtracking
        void mazeRecursion(Node* current, std::vector<Node*> *board);

    };
}


#endif // MAZEIMG_IMAGE_RECURSIVEBACKTRACK_H