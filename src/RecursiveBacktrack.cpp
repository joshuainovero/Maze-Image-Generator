/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: RecursiveBacktracker.cpp
 * Implementation file for RecursiveBacktracker.h
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

#include <MazeImage++/utils/RecursiveBacktrack.h>

namespace mazeimg_library{

    RecursiveBacktrack::RecursiveBacktrack(std::vector<Node*> *tiles_, uint32_t totalRows_) 
        : Algorithm(tiles_, totalRows_){
    }

    RecursiveBacktrack::~RecursiveBacktrack() {}

    void RecursiveBacktrack::mazeRecursion(Node* current, std::vector<Node*> *board){
       current->setVisited();
        
        // Shuffle the vector of neighbors of the current node
        std::vector<Node*> randomized_neighbors = current->g_neighbors();
        std::random_shuffle(randomized_neighbors.begin(), randomized_neighbors.end());

        // Visit random neighbors
        for (auto neighbor : randomized_neighbors){
            Node* next_neighbor = nullptr;

            if (neighbor->g_nCoord().first > current->g_nCoord().first){
                if (!(board[neighbor->g_nCoord().first + 1][neighbor->g_nCoord().second])->isVisited()){
                    next_neighbor = board[neighbor->g_nCoord().first + 1][neighbor->g_nCoord().second];
                }
            }
            else if (neighbor->g_nCoord().first < current->g_nCoord().first){
                if (!neighbor->g_nCoord().first == 0){
                    if (!(board[neighbor->g_nCoord().first - 1][neighbor->g_nCoord().second])->isVisited()){
                        next_neighbor = board[neighbor->g_nCoord().first - 1][neighbor->g_nCoord().second];
                    }
                }          
            }
            else if (neighbor->g_nCoord().second > current->g_nCoord().second){
                if (!(board[neighbor->g_nCoord().first][neighbor->g_nCoord().second + 1])->isVisited()){
                    next_neighbor = board[neighbor->g_nCoord().first][neighbor->g_nCoord().second + 1];
                }            
            }
            else if (neighbor->g_nCoord().second < current->g_nCoord().second){
                if (!(board[neighbor->g_nCoord().first][neighbor->g_nCoord().second - 1])->isVisited()){
                    next_neighbor = board[neighbor->g_nCoord().first][neighbor->g_nCoord().second - 1];
                }             
            }
            if (next_neighbor != nullptr){
                neighbor->setVisited();
                mazeRecursion(next_neighbor, board);
            }

        }
  
    }

    std::vector<Node*>* RecursiveBacktrack::run(){
        
        // Reset all nodes to whites
        for (size_t i = 0; i < totalRows; ++i){
            for (Node* node : tiles[i])
                node->reset();
        }

        // Iterate to all nodes and establish its neighbors
        updateTileNeighbors();
        
        // The node that the algorithm will first visit
        Node* current = tiles[0][0];

        // Call DFS helper function
        mazeRecursion(current, tiles);

        for (size_t i = 0; i < totalRows; ++i){
            for (Node *node : tiles[i]){
                if (!node->isVisited()){
                    node->setWall();
                }
            }
        }
        return tiles;
    }

}