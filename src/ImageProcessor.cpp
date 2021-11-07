/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: ImageProcessing.cpp
 * Implementation file for ImageProcessing.h
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

#include <MazeImage++/utils/ImageProcessor.h>

namespace mazeimg_library{

    ImageProcessor::ImageProcessor(M_SIZE m_size) : board(nullptr)  {
        srand(time(0));
        newBoard(m_size);

        // Push back temporary values to imagePixels
        for (size_t i = 0; i < Board::img_SIZE; ++i){
            for (size_t k = 0; k < Board::img_SIZE; ++k){
                imagePixels[i].push_back(NODETYPES::WHITE); 
            }
        } 
    }

    void ImageProcessor::newBoard(M_SIZE m_size){
        if (board != nullptr)
            delete board;
        board = new Board(m_size);
    }

    void ImageProcessor::processImage(const char* output, IMG_FORMAT img_f){

        // Check if output file exists in the current directory
        assert_((std::ifstream(output + std::string(".png"))).fail(), 
            "Name of file is already existing in the directory!");
        assert_((std::ifstream(output + std::string(".jpg"))).fail(), 
            "Name of file is already existing in the directory!");

        // Generate maze by calling the maze algorithm and return the modified graph to tiles_  
        std::string mazeSizeMsg = "Generating " + std::string(
            ((board->g_m_size() == s) ? "small" : 
            (board->g_m_size() == m) ? "medium" : 
            (board->g_m_size() == l) ? "large" : "Unknown")) + " maze...\n";
        _COLOREDTEXT(mazeSizeMsg.c_str(), _YELLOW);      
        std::vector<Node*> *tiles_ = board->mazeAlgo->run();
        printf("Maze generated successfully.\n");
    
        // Adjust pixel positions of the actual 1100x1100 image based on the generated maze
        printf("Processing maze image...\n");
        int xcounter = 0, ycounter = 0;
        for (size_t col = 0; col < board->g_totalRows(); ++col){
            for (size_t row = 0; row < board->g_totalRows(); ++row){
                NODETYPES currentNodeType = tiles_[col][row]->g_nodeType();
                for (size_t row_msize = 0; row_msize < board->g_m_size(); ++row_msize){
                    for (size_t col_msize = 0; col_msize < board->g_m_size(); ++col_msize){
                        imagePixels[ycounter + col_msize][xcounter] = currentNodeType;
                    }
                    xcounter++;
                }
            }
            xcounter = 0;
            ycounter += board->g_m_size();

        }
        xcounter = 0;
        ycounter = 0;

        printf("Sucessfully processed the maze image...\n");
        createImage(output, img_f);

        // If solution is enabled
        if (solution){
            printf("Solution is enabled - Generating maze with solution...\n");
            // Check if output solution file exists in the current directory
            assert_((std::ifstream(output + std::string("_solution.png"))).fail(), 
                "Name of file is already existing in the directory!");
            assert_((std::ifstream(output + std::string("_solution.jpg"))).fail(), 
                "Name of file is already existing in the directory!");

            // Call search algorithm
            tiles_ = board->currentAlgorithm->run();
            printf("Maze with solution sucessfully generated.\n");
            for (size_t col = 0; col < board->g_totalRows(); ++col){
                for (size_t row = 0; row < board->g_totalRows(); ++row){
                    NODETYPES currentNodeType = tiles_[col][row]->g_nodeType();
                    for (size_t row_msize = 0; row_msize < board->g_m_size(); ++row_msize){
                        for (size_t col_msize = 0; col_msize < board->g_m_size(); ++col_msize){
                            imagePixels[ycounter + col_msize][xcounter] = currentNodeType;
                        }
                        xcounter++;
                    }
                }
                xcounter = 0;
                ycounter += board->g_m_size();
            }
            printf("Successfully processed maze with solution image.\n");
            createImage((std::string(output) + "_solution").c_str(), img_f);
        }
        _COLOREDTEXT("\nFinished without errors.\n\n\n", _GREEN);
    }

    void ImageProcessor::createImage(const char* output, IMG_FORMAT img_f){
        
        printf("Creating image...\n");
        // Process image to PPM format
        std::string outputPPM = output + std::string(".ppm");
        std::string outputCompressed =  output + std::string((img_f == IMG_FORMAT::PNG) ? ".png" : ".jpg");
        std::ofstream image(outputPPM);
            image << ImageProcessor::ppm_VARIATION << std::endl << 
            Board::img_SIZE << " " << Board::img_SIZE << 
            std::endl << ImageProcessor::max_RGB << std::endl;

            for (size_t i = 0; i < Board::img_SIZE; ++i){
                for (size_t k = 0; k < Board::img_SIZE; ++k){
                    if (imagePixels[i][k] == NODETYPES::WALL)
                        image << ImageProcessor::wall_RGB << std::endl;
                    else if (imagePixels[i][k] == NODETYPES::WHITE)
                        image << ImageProcessor::path_RGB << std::endl;
                    else if (imagePixels[i][k] == NODETYPES::ROUTE)
                        image << ImageProcessor::route_RGB << std::endl;
                }
            }

        image.close();
        printf("Image successfully processed to PPM format.\n");
        printf("Compressing PPM file to %s...\n", outputCompressed.c_str());

        // Convert PPM format to JPG/PNG
        cimg_.load(outputPPM.c_str());
        cimg_.save(outputCompressed.c_str());
        printf("Successfully compressed the file.\n");
        remove(outputPPM.c_str()); 
    }

    void ImageProcessor::setSearchAlgorithm(SEARCHALGOS s_type){
        board->currentAlgorithm = board->searchAlgorithms[s_type];
    }
}