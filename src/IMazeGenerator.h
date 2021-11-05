#ifndef IMAZE_GENERATOR_H_
#define IMAZE_GENERATOR_H_
#include "Board.h"
#include <iostream>
#include <fstream>

// Custom assertion messages
#define assert_(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), "\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl, abort(), 0) : 1

enum class IMG_FORMAT {JPG, PNG}; // Supported formats for output image

namespace MazeIMG {

    class IMazeGenerator {
    public:

        // Constructor with immediate maze size specification
        IMazeGenerator(M_SIZE m_size);

        // Changes the initial size of the maze that was set by the constructor
        void setMazeSize(M_SIZE m_size);

        // Calls the maze algorithm and saves the result as an image
        void processImage(const char* output, IMG_FORMAT img_f);

    private:
        inline static const char* wall_RGB = "0 0 0";        // RGB values for color black - wall nodes
        inline static const char* path_RGB = "255 255 255";  // RGB values for color white - path nodes

        std::vector<int> imageVec[Board::img_SIZE]; // 2D vector that stores the x and y values of the image
        Board            board;                     // Instance of class Board


        // Copy constructor and assignment is disabled
        IMazeGenerator(const IMazeGenerator&);
        IMazeGenerator& operator=(const IMazeGenerator&);

    };
    
}

#endif