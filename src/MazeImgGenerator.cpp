/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: MazeImgGenerator.cpp
 * Implementation file for MazeImgGenerator.h
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

#include <MazeImage++/utils/MazeImgGenerator.h>

namespace mazeimg_library{
    
    MazeImgGenerator::MazeImgGenerator(M_SIZE m_size) : img_processor(m_size){}

    void MazeImgGenerator::setMazeSize(M_SIZE m_size){ img_processor.newBoard(m_size); }

    void MazeImgGenerator::generate(const char* output, IMG_FORMAT img_f){
        img_processor.processImage(output, img_f);
    }

    void MazeImgGenerator::enableSolution(bool cnd){
        img_processor.solution = cnd;
    }

    void MazeImgGenerator::setSearchAlgorithm(SEARCHALGOS s_type){
        img_processor.setSearchAlgorithm(s_type);
    }

}
