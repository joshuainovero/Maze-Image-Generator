#include "MazeImgGenerator.h"

namespace mazeimg_library{
    
    MazeImgGenerator::MazeImgGenerator(M_SIZE m_size) : board(m_size){
        for (size_t i = 0; i < Board::img_SIZE; ++i){
            for (size_t k = 0; k < Board::img_SIZE; ++k){
                imageVec[i].push_back(1); 
            }
        } 
    }

    void MazeImgGenerator::setMazeSize(M_SIZE m_size){
        board.deallocateBoard();
        board.constructBoard(m_size);
    }

    void MazeImgGenerator::processImage(const char* output, IMG_FORMAT img_f){
        assert_((std::ifstream(output + std::string(".png"))).fail(), 
            "Name of file is already existing in the directory!");
        assert_((std::ifstream(output + std::string(".jpg"))).fail(), 
            "Name of file is already existing in the directory!");

        std::vector<Node*> *tiles_ = board.rBacktracker();
        printf("Processing image...\n");
        printf("Image size: %u x %u\n", Board::img_SIZE, Board::img_SIZE);

        int xcounter = 0, ycounter = 0;
        for (size_t col = 0; col < board.g_totalRows(); ++col){
            for (size_t row = 0; row < board.g_totalRows(); ++row){
                int wallType = (!tiles_[col][row]->isVisited()) ? 0 : 1; 
                for (size_t row_msize = 0; row_msize < board.g_m_size(); ++row_msize){
                    for (size_t col_msize = 0; col_msize < board.g_m_size(); ++col_msize){
                        imageVec[ycounter + col_msize][xcounter] = wallType;
                    }
                    xcounter++;
                }
            }
            xcounter = 0;
            ycounter += board.g_m_size();

        }

        std::string outputPPM = output + std::string(".ppm");
        std::string outputCompressed =  output + std::string((img_f == IMG_FORMAT::PNG) ? ".png" : ".jpg");
        std::ofstream image(outputPPM);
            image << "P3" << std::endl << 
            Board::img_SIZE << " " << Board::img_SIZE << 
            std::endl << "255" << std::endl;

            for (size_t i = 0; i < Board::img_SIZE; ++i){
                for (size_t k = 0; k < Board::img_SIZE; ++k){
                    if (imageVec[i][k] == 0)
                        image << wall_RGB << std::endl;
                    else if (imageVec[i][k] == 1)
                        image << path_RGB << std::endl;
                }
            }
        image.close();

        printf("Image successfully processed to PPM format.\n\n");
        printf("Compressing PPM file to %s...\n", outputCompressed.c_str());

        cimg_library::CImg<unsigned char> im(outputPPM.c_str());
        im.save(outputCompressed.c_str());
        // system(("magick convert " + outputPPM + " " + outputCompressed).c_str());
        printf("Successfully compressed the file.\n\n");
        printf("Finished without errors.\n\n\n");
        remove(outputPPM.c_str());
    }

}