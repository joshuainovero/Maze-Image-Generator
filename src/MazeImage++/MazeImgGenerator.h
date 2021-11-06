#ifndef MAZEIMG_GENERATOR_H_
#define MAZEIMG_GENERATOR_H_
#include "Board.h"
#include "../../Cimg/CImg.h"
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

namespace mazeimg_library {

    class MazeImgGenerator {
    public:

        // Constructor with immediate maze size specification
        MazeImgGenerator(M_SIZE m_size);

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
        MazeImgGenerator(const MazeImgGenerator&);
        MazeImgGenerator& operator=(const MazeImgGenerator&);

    };
    
}

#endif // MAZEIMG_GENERATOR_H_