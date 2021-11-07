#ifndef MAZEIMG_IMAGE_VECTOR2D_H
#define MAZEIMG_IMAGE_VECTOR2D_H
#include <type_traits>
#include <stdint.h>

namespace mazeimg_library{

    template<typename T>
    struct _isInt_{ static const bool _v = false; };

    template<typename T>
    struct _isFloat_{ static const bool _v = false; };

    template<typename T>
    struct _isUint_{ static const bool _v = false; };

    template<typename T>
    struct _isDouble_{ static const bool _v = false; };


    template<>
    struct _isInt_<int>{ static const bool _v = true; };

    template<>
    struct _isFloat_<float>{ static const bool _v = true; };

    template<>
    struct _isUint_<uint32_t>{ static const bool _v = true; };

    template<>
    struct _isDouble_<double>{ static const bool _v = true; };


    template<typename T>
    class Vector2D{
        
        // int, uint32_t, float, and double are only accepted
        static_assert(_isInt_<T>::_v || _isFloat_<T>::_v || _isUint_<T>::_v || _isDouble_<T>::_v, 
            "T must be int/uint32_t/float/double");

        public:
            T x, y; // x and y values of the 2D vector

            // Constructor that accepts numerical numbers
            Vector2D(T _x, T _y) : x(_x), y(_y){};
    };
}

#endif // MAZEIMG_IMAGE_VECTOR2D_H