/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Board.cpp
 * Implementation file for Board.h
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

#include "Board.h"

namespace mazeimg_library{

    Board::Board(M_SIZE m_size){
        constructBoard(m_size);
    }

    void Board::constructBoard(M_SIZE m_size){
        this->m_size = m_size;
        totalRows = Board::img_SIZE/m_size;

        // Allocate new board with respect to totalRows
        tiles = new std::vector<Node*>[totalRows];
        for (size_t i = 0; i < totalRows; ++i){
            for (size_t k = 0; k < totalRows; ++k){
                tiles[i].push_back(new Node(i, k, totalRows));
            }
        }
    }

    void Board::deallocateBoard(){
        for (size_t i = 0; i < totalRows; ++i){
            for (Node *node : tiles[i]) 
                delete node;
            tiles[i].clear();
        }
        delete [] tiles;
    }

    void Board::mazeRecursion(Node* current, std::vector<Node*> *board){
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

    std::vector<Node*> *Board::rBacktracker(){

        // Reset all nodes to whites
        for (size_t i = 0; i < totalRows; ++i){
            for (Node* node : tiles[i])
                node->reset();
        }

        _COLOREDTEXT("Generating maze...\n", _YELLOW);
        const char *sizeChar;
        switch (m_size){
            case M_SIZE::l: sizeChar = "Large"; break;
            case M_SIZE::m: sizeChar = "Medium"; break;
            case M_SIZE::s: sizeChar = "Small"; break;
            default: break;
        }
        printf("Maze size: %s\nTotal rows: %u\n", sizeChar, m_size);

        // Iterate to all nodes and establish its neighbors
        for (size_t i = 0; i < totalRows; ++i){
            for (auto node : tiles[i]){
                node->updateNeighbors(tiles);
            }
        }

        // The node that the algorithm will first visit
        Node* current = tiles[0][0];

        // Call DFS helper function
        mazeRecursion(current, tiles);

        printf("Maze successfully generated.\n\n");
        return tiles;
    }

    uint32_t Board::g_totalRows() const { return totalRows; }

    M_SIZE Board::g_m_size() const { return m_size; }

}