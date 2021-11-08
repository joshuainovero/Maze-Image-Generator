/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Dijkstra.cpp
 * Implementation file for Dijkstra.h
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

#include <MazeImage++/utils/Dijkstra.h>

namespace mazeimg_library{

    Dijkstra::Dijkstra(std::vector<Node*> *tiles_, uint32_t totalRows_)
        : WeightedSearch(tiles_, totalRows_) {}

    Dijkstra::~Dijkstra() {}

    std::vector<Node*>* Dijkstra::run(){
        updateTileNeighbors();

        for (size_t i = 0; i < totalRows; ++i){
            for (size_t k = 0; k < totalRows; ++k){
                gScore[tiles[i][k]] = INT_MAX;
            }
        }

        gScore[startNode] = 0;
        priorityQueue.insert(std::make_pair(gScore[startNode], startNode));

        while(!priorityQueue.empty()){
            Node* currentNode = (priorityQueue.begin())->second;

            uint32_t currentDist = (priorityQueue.begin())->first;
            priorityQueue.erase(priorityQueue.begin());

            for (auto neighbor : currentNode->g_neighbors()){
                if (currentDist + 1 < gScore[neighbor]){
                    auto findNode = priorityQueue.find(std::make_pair(gScore[neighbor], neighbor));
                    if (findNode != priorityQueue.end())
                        priorityQueue.erase(findNode);

                    gScore[neighbor] = currentDist + 1;
                    priorityQueue.insert(std::make_pair(gScore[neighbor], neighbor));
                    previousNode[neighbor] = currentNode;
                }
            }
        }

        reconstructPath(endNode);
        resetAttributes();
        
        return tiles;
    }

    void Dijkstra::resetAttributes(){
        previousNode.clear();
        priorityQueue.clear();
        gScore.clear();
    }
}