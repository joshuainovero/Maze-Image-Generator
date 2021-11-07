/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Node.cpp
 * Implementation file for Node.h
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

#include <MazeImage++/utils/Node.h>

namespace mazeimg_library{

    Node::Node(uint32_t row, uint32_t col, uint32_t totalRows){
        this->row = row;
        this->col = col;
        this->totalRows = totalRows;
        visitedNode = false;
        nodeType = NODETYPES::WHITE;
    }

    void Node::updateNeighbors(std::vector<Node*> *board){
        neighbors.clear();
        if (row < totalRows - 1 && (board[row + 1][col]->nodeType != NODETYPES::WALL))
            neighbors.push_back(board[row + 1][col]);

        if (row > 0 && (board[row - 1][col]->nodeType != NODETYPES::WALL))
            neighbors.push_back(board[row - 1][col]);

        if (col < totalRows - 1 && (board[row][col + 1]->nodeType != NODETYPES::WALL))
            neighbors.push_back(board[row][col + 1]);

        if (col > 0 && (board[row][col - 1]->nodeType != NODETYPES::WALL))
            neighbors.push_back(board[row][col - 1]);
    }

    std::pair<uint32_t, uint32_t> Node::g_nCoord() const { return std::make_pair(row, col); }

    std::vector<Node*> Node::g_neighbors() const { return neighbors; }

    NODETYPES Node::g_nodeType() const { return nodeType; }

    void Node::setVisited() {visitedNode = true; }

    void Node::setRoute() { nodeType = NODETYPES::ROUTE; }

    void Node::setWall() { nodeType = NODETYPES::WALL; }

    void Node::reset() { visitedNode = false; nodeType = NODETYPES::WHITE;}

    bool Node::isVisited() const { return visitedNode; }

}