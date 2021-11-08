#ifndef MAZEIMG_IMAGE_WEIGHTEDSEARCH_H
#define MAZEIMG_IMAGE_WEIGHTEDSEARCH_H

#include <MazeImage++/utils/Algorithm.h>
#include <unordered_map>
#include <utility>
#include <set>

namespace mazeimg_library{

    class WeightedSearch : public Algorithm{
    public:

        // Constructor copies tiles and totalRows
        WeightedSearch(std::vector<Node*> *tiles_, uint32_t totalRows_);

        // Destructor
        virtual ~WeightedSearch() override;
        
        // Pure virtual function - derived search classes will implement this to run their algorithm
        virtual std::vector<Node*>* run() = 0;

    protected:

        Node* startNode; // Starting node
        Node* endNode;   // Target node

        std::unordered_map<Node*, Node*> previousNode; // Parent hash map

        // Reconstructs the route taken after calling the search algorithm
        void reconstructPath(Node* current);
        
        // Resets STL attributes
        virtual void resetAttributes() = 0;
    };

}

#endif // MAZEIMG_IMAGE_WEIGHTEDSEARCH_H