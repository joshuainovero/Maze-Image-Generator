#include <MazeImage++/utils/WeightedSearch.h>

namespace mazeimg_library{

    WeightedSearch::WeightedSearch(std::vector<Node*> *tiles_, uint32_t totalRows_) 
        : Algorithm(tiles_, totalRows_){
        startNode = tiles[0][0];
        endNode = tiles[totalRows - 1][totalRows - 1];
    }

    WeightedSearch::~WeightedSearch() {}

    void WeightedSearch::reconstructPath(Node* current){

        while (current != startNode){
            current->setRoute();
            current = previousNode[current];
        }
        current->setRoute();
    }


}
