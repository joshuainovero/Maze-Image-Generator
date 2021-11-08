/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Astar.h
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

#ifndef MAZEIMG_IMAGE_ASTAR_H
#define MAZEIMG_IMAGE_ASTAR_H
#include <MazeImage++/utils/WeightedSearch.h>
#include <MazeImage++/utils/Vector2D.h>
#include <unordered_map>
#include <utility>
#include <set>

namespace mazeimg_library{

    typedef mazeimg_library::Vector2D<double> vec2Double;

    class Astar : public WeightedSearch{
    public:

        // Constructor copies tiles and totalRows
        Astar(std::vector<Node*> *tiles_, uint32_t totalRows_);

        // Destructor
        virtual ~Astar() override;
        
        // Function to run A* algorithm
        virtual std::vector<Node*>* run() override;

    private:

        std::set<std::pair<std::pair<double, uint32_t>, Node*>> priorityQueue; // Priority queue of f scores

        std::unordered_map<Node*, uint32_t> gScore; // Stored distances from the starting node to current node
        std::unordered_map<Node*, double>   fScore; // Sum of a current g score and heuristic cost

        // A heuristic function that uses manhattan distance
        double calcHeuristic(vec2Double p1, vec2Double p2);

        // Resets STL attributes
        virtual void resetAttributes() override;
    };

}

#endif // MAZEIMG_IMAGE_Astar_H