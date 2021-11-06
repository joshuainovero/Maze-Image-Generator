#include "Node.h"

namespace mazeimg_library{

    Node::Node(uint32_t row, uint32_t col, uint32_t totalRows){
        this->row = row;
        this->col = col;
        this->totalRows = totalRows;
        wall = false;
        visitedNode = false;
    }

    void Node::updateNeighbors(std::vector<Node*> *board){
        neighbors.clear();
        if (row < totalRows - 1 && !(board[row + 1][col]->wall))
            neighbors.push_back(board[row + 1][col]);

        if (row > 0 && !(board[row - 1][col]->wall))
            neighbors.push_back(board[row - 1][col]);

        if (col < totalRows - 1 && !(board[row][col + 1]->wall))
            neighbors.push_back(board[row][col + 1]);

        if (col > 0 && !(board[row][col - 1]->wall))
            neighbors.push_back(board[row][col - 1]);
    }

    std::pair<uint32_t, uint32_t> Node::g_nCoord() const { return std::make_pair(row, col); }

    std::vector<Node*> Node::g_neighbors() const { return neighbors; }

    void Node::setVisited() {visitedNode = true;}

    void Node::reset() { visitedNode = false; }

    bool Node::isVisited() const { return visitedNode; }

}