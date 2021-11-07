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

#include <MazeImage++/utils/Board.h>

namespace mazeimg_library{

    Board::Board(M_SIZE m_size) : mazeAlgo(nullptr){
        constructBoard(m_size);
        mazeAlgo = new RecursiveBacktrack(tiles, totalRows);
        searchAlgorithms.push_back(new Dijkstra(tiles, totalRows));
        searchAlgorithms.push_back(new Astar(tiles, totalRows));
        currentAlgorithm = searchAlgorithms[SEARCHALGOS::DIJKSTRA];
    }

    Board::~Board(){
        deallocateBoard();
        delete mazeAlgo;

        for (Algorithm *algo : searchAlgorithms)
            delete algo;
        searchAlgorithms.clear();
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

    uint32_t Board::g_totalRows() const { return totalRows; }

    M_SIZE Board::g_m_size() const { return m_size; }

}