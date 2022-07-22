//
//  mat.hpp
//  javacv
//
//  Created by Denis Makogon on 18.07.2022.
//

#ifndef mat_hpp
#define mat_hpp

#include <stdlib.h>

typedef unsigned char uchar;

struct MatSize {
    int* p;
};


struct MatStep {
    size_t* p;
    size_t buf[2];
};

/*
 Represents cv::Mat class data fields
*/
struct Mat {
    uchar* data;

    int width;
    int height;
    int channels;
    int flags;
    int dimentions;
    
    const uchar* datastart;
    const uchar* dataend;
    const uchar* datalimit;
    
    struct MatStep* step;
    struct MatSize* size;
};

#endif /* mat_hpp */
