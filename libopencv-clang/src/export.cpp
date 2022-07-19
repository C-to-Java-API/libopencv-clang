//
//  _export.cpp
//  javacv
//
//  Created by Denis Makogon on 18.07.2022.
//

#include "include/mat_type.h"

#include "opencv2/core/mat.hpp"

using namespace std;

void CV_MatToMat(cv::Mat& image, Mat& exMat) {
    unsigned long size = image.total() * image.elemSize();
    char * bytes = new char[size];
    memcpy(bytes,image.data,size * sizeof(char));
    exMat = (Mat) {
        .data = bytes,
        .width = image.cols,
        .height = image.rows,
        .channels = image.channels(),
        .dimentions = image.dims,
        .flags = image.flags,
    };
}

void matToCV_Mat(Mat& exMat, cv::Mat& mat) {
    int* sizes = new int[2] {exMat.height, exMat.width};
    mat = cv::Mat(exMat.dimentions, sizes, CV_8UC(exMat.channels), exMat.data).clone();
}
