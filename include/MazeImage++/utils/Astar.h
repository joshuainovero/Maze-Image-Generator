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
#include <MazeImage++/utils/Algorithm.h>
#include <MazeImage++/utils/Vector2D.h>
#include <unordered_map>
#include <utility>
#include <set>

namespace mazeimg_library{

    typedef mazeimg_library::Vector2D<double> vec2Double;

    class Astar : public Algorithm{
    public:

        // Constructor
        Astar(std::vector<Node*> *tiles_, uint32_t totalRows_);

        // Destructor
        virtual ~Astar() override;
        
        // Function to run A* algorithm
        virtual std::vector<Node*>* run() override;

    private:

        // A heuristic function that uses manhattan distance
        double calcHeuristic(vec2Double p1, vec2Double p2);

        // Reconstructs the route taken after calling the search algorithm
        void reconstructPath(std::unordered_map<Node*, Node*> previousNode,
            Node* current, Node* startNode);
    };

}

#endif // MAZEIMG_IMAGE_Astar_H