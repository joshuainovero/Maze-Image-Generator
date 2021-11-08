/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Dijkstra.h
 * Derived class of Weighted.h
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

#ifndef MAZEIMG_IMAGE_DIJKSTRA_H
#define MAZEIMG_IMAGE_DIJKSTRA_H
#include <MazeImage++/utils/WeightedSearch.h>
#include <unordered_map>
#include <utility>
#include <set>

namespace mazeimg_library{

    class Dijkstra : public WeightedSearch{
    public:

        // Constructor copies tiles and totalRows
        Dijkstra(std::vector<Node*> *tiles_, uint32_t totalRows_);

        // Destructor
        virtual ~Dijkstra() override;
        
        // Function to run Dijkstra's algorithm
        virtual std::vector<Node*>* run() override;

    private:

        std::set<std::pair<uint32_t, Node*>> priorityQueue; // Priority queue of g scores
        std::unordered_map<Node*, uint32_t>  gScore;        // Stored distances from the starting node to current node

        // Resets STL attributes
        virtual void resetAttributes() override;

    };

}

#endif // MAZEIMG_IMAGE_DIJKSTRA_H