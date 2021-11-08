/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Astar.cpp
 * Implementation file for Astar.h
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

#include <MazeImage++/utils/Astar.h>

namespace mazeimg_library{
    
    Astar::Astar(std::vector<Node*> *tiles_, uint32_t totalRows_)
        : WeightedSearch(tiles_, totalRows_) {}

    Astar::~Astar() {}

    double Astar::calcHeuristic(vec2Double p1, vec2Double p2){
        return (std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y));
    }

    std::vector<Node*>* Astar::run(){
        updateTileNeighbors();

        uint32_t precedence = 0;
        priorityQueue.insert(std::make_pair(std::make_pair(0, precedence), startNode));

        for (size_t i = 0; i < totalRows; ++i){
            for (size_t k = 0; k < totalRows; ++k){
                gScore[tiles[i][k]] = INT_MAX;
            }
        }
        
        gScore[startNode] = 0;

        for (size_t i = 0; i < totalRows; ++i){
            for (size_t k = 0; k < totalRows; ++k){
                fScore[tiles[i][k]] = INT_MAX;
            }
        }
  
        fScore[startNode] = calcHeuristic
            (Vector2D<double>(startNode->g_nCoord().first, startNode->g_nCoord().second), 
             Vector2D<double>(endNode->g_nCoord().first,endNode->g_nCoord().second));

        std::vector<Node*> priorityQueueTracker = {startNode};

        while (!priorityQueue.empty()){
            auto currentQueue = *(priorityQueue.begin());
            Node *current = currentQueue.second;

            auto it1 = std::find(priorityQueueTracker.begin(), priorityQueueTracker.end(), current);
            priorityQueue.erase(priorityQueue.begin());
            if (it1 != priorityQueueTracker.end())
                priorityQueueTracker.erase(it1);

            if (current == endNode){
                reconstructPath(current);
                break;
            }

            for (auto neighbor : current->g_neighbors()){
                uint32_t temp_g_score = gScore[current] + 1;

                if (temp_g_score < gScore[neighbor]){
                    previousNode[neighbor] = current;
                    gScore[neighbor] = temp_g_score;
                    fScore[neighbor] = temp_g_score + calcHeuristic
                        (Vector2D<double>(neighbor->g_nCoord().first, neighbor->g_nCoord().second), 
                        Vector2D<double>(endNode->g_nCoord().first, endNode->g_nCoord().second));
                    
                    if (std::find(priorityQueueTracker.begin(), priorityQueueTracker.end(), neighbor) == priorityQueueTracker.end()){
                        precedence += 1;
                        priorityQueue.insert(std::make_pair(std::make_pair(fScore[neighbor], precedence), neighbor));
                        priorityQueueTracker.push_back(neighbor);
                        
                    }
                }
            }
        }
        
        resetAttributes();
        return tiles;

    }

    void Astar::resetAttributes(){
        previousNode.clear();
        priorityQueue.clear();
        gScore.clear();
        fScore.clear();
    }

}