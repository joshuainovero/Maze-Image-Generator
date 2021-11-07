/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: ImageProcessor.h
 * A class that processes the generated maze into an image
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

#ifndef MAZEIMG_IMAGE_PROCESSOR_H
#define MAZEIMG_IMAGE_PROCESSOR_H
#include <MazeImage++/utils/Board.h>
#include <MazeImage++/utils/CImg/CImg.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <cstring>

enum class IMG_FORMAT {JPG, PNG}; // Supported formats for output image

namespace mazeimg_library{

    class ImageProcessor{
    public:

        // Constructor using the specified size of a single node
        ImageProcessor(M_SIZE m_size);

        // Deallocates board and allocates new board according to m_size
        void newBoard(M_SIZE m_size);

        // Processes the image according to the generated maze
        void processImage(const char* output, IMG_FORMAT img_f);
        
        // Creates a JPG/PNG image after processing the image
        void createImage(const char* output, IMG_FORMAT img_f);

        // Sets the search algorithm to be used
        void setSearchAlgorithm(SEARCHALGOS s_type);

        bool solution; // Pathfinding algorithm will be implemented if true

    private:

        cimg_library::CImg<unsigned char> cimg_; // Object for image convertion

        std::vector<NODETYPES> imagePixels[Board::img_SIZE]; // 2D vector that store x and y pixel values of the image
        Board                  *board;                       // Instance of class Board

        inline static const char* ppm_VARIATION = "P3";      // Variation of PPM
        inline static const char* max_RGB = "255";           // Maximum RGB value
        inline static const char* wall_RGB = "0 0 0";        // RGB values for color black - wall nodes
        inline static const char* path_RGB = "255 255 255";  // RGB values for color white - path nodes
        inline static const char* route_RGB = "255 0 0";     // RGB value for color red - route nodes


    };  
}


#endif // MAZEIMG_IMAGE_PROCESSOR_H