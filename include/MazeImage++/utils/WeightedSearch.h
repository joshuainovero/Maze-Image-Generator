/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: WeightedSearch.h
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

#ifndef MAZEIMG_IMAGE_WEIGHTEDSEARCH_H
#define MAZEIMG_IMAGE_WEIGHTEDSEARCH_H

#include <MazeImage++/utils/Algorithm.h>
#include <unordered_map>
#include <utility>
#include <set>

namespace mazeimg_library{

    class WeightedSearch : public Algorithm{
    public:

        // Constructor copies tiles and totalRows
        WeightedSearch(std::vector<Node*> *tiles_, uint32_t totalRows_);

        // Destructor
        virtual ~WeightedSearch() override;
        
        // Pure virtual function - derived search classes will implement this to run their algorithm
        virtual std::vector<Node*>* run() = 0;

    protected:

        Node* startNode; // Starting node
        Node* endNode;   // Target node

        std::unordered_map<Node*, Node*> previousNode; // Parent hash map

        // Reconstructs the route taken after calling the search algorithm
        void reconstructPath(Node* current);
        
        // Resets STL attributes
        virtual void resetAttributes() = 0;
    };

}

#endif // MAZEIMG_IMAGE_WEIGHTEDSEARCH_H