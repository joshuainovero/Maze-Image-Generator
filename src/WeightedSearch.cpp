/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: WeightedSearch.cpp
 * Implementation file for WeightedSearch.h
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

#include <MazeImage++/utils/WeightedSearch.h>

namespace mazeimg_library{

    WeightedSearch::WeightedSearch(std::vector<Node*> *tiles_, uint32_t totalRows_) 
        : Algorithm(tiles_, totalRows_){
        
        // Start node will be at the top left of the image
        startNode = tiles[0][0];

        // End node will be at the bottom right of the image
        endNode = tiles[totalRows - 1][totalRows - 1];
    }

    WeightedSearch::~WeightedSearch() {}

    void WeightedSearch::reconstructPath(Node* current){

        while (current != startNode){
            current->setRoute();
            current = previousNode[current];
        }
        current->setRoute();
    }


}
