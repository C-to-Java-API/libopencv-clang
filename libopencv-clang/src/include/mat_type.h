//
//  mat.hpp
//  javacv
//
//  Created by Denis Makogon on 18.07.2022.
//

#ifndef mat_hpp
#define mat_hpp

/*
 Represents cv::Mat class data fields
*/
struct Mat {
    char* data;
    int width;
    int height;
    int channels;
    int flags;
    int dimentions;
};

#endif /* mat_hpp */
