/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: Algorithm.cpp
 * Implementation file for Algorithm.cpp
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

#include <MazeImage++/utils/Algorithm.h>

namespace mazeimg_library{

    Algorithm::Algorithm(std::vector<Node*> *tiles_, uint32_t totalRows_) : 
        tiles(tiles_), totalRows(totalRows_){}

    Algorithm::~Algorithm() {}

    void Algorithm::updateTileNeighbors(){
        for (size_t i = 0; i < totalRows; ++i){
            for (auto node : tiles[i]){
                node->updateNeighbors(tiles);
            }
        }
    }

}