/*****************************************************************************
 * 
 * MazeImage++ - A library that generates maze images
 * Copyright (C) - 2021 Joshua Inovero (joshinovero@gmail.com)
 * 
 * File: CLIOutput.h
 * This file is used for colored output texts
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

#ifndef MAZEIMG_IMAGE_CLIOUTPUT_H_

// Windows system
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #include <Windows.h>
    #define _RED     0x0C
    #define _GREEN   0x0A
    #define _YELLOW  0x0E
    #define _DEFAULT 0x07
    #define _COLOREDTEXT(_msg, _color) do { \
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color); \
        printf("%s", _msg); \
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _DEFAULT); \
    } while(false)

// Unix systems
#elif __APPLE__ || __linux__
    #define _RED     31
    #define _GREEN   32
    #define _YELLOW  43
    #define _DEFAULT \033[0m
    #define _COLOREDTEXT(_msg, _color) do { \
        printf("\033[0;%dm%s\033[0m", _color, _msg); \
    } while(false)

#else
# error "Error"
#endif

// Custom assertion messages
#define assert_(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), "\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl, abort(), 0) : 1

#define MAZEIMG_IMAGE_CLIOUTPUT_H_
#endif // MAZEIMG_IMAGE_CLIOUTPUT_H_