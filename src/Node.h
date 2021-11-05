#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <stdint.h>
#include <string>
#include <utility>

namespace MazeIMG{

    class Node {
    public:

        // Constructor that accepts uint values of row, column, and total rows of the grid/board
        Node(uint32_t row, uint32_t col, uint32_t totalRows);

        // Establish connections to surrounding nodes
        void updateNeighbors(std::vector<Node*> *board); 

        // Set the attribute 'visitedNode' to true
        void setVisited();

        // Reset the state of the node
        void reset();

        // Getters for attributes: neighbors, visitedNode, row, and column
        std::vector<Node*> g_neighbors() const;
        std::pair<uint32_t, uint32_t> g_nCoord() const;
        bool isVisited() const;

    private:

        std::vector<Node*> neighbors; // Neighbors of this instance in the grid/board

        uint32_t totalRows; // total number of rows in the grid/board
        uint32_t row, col;  // Row and column position of this instance in the grid/board

        bool visitedNode; // True if this instance was visited during recursive backtrack
        bool wall;        // True if if this instance is a wall node

    };

}

#endif // NODE_H_