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
    uchar * bytes = new uchar[size];
    memcpy(bytes,image.data,size * sizeof(uchar));

    auto stepMat = (MatStep) {
        .p = image.step.p,
        .buf = {*image.step.buf}
    };
    auto sizeMat = (MatSize) {
        .p = image.size.p
    };
    
    exMat = (Mat) {
        .data = bytes,
        .width = image.cols,
        .height = image.rows,
        .channels = image.channels(),
        .dimentions = image.dims,
        .flags = image.flags,
        .datastart = image.datastart,
        .dataend = image.dataend,
        .datalimit = image.datalimit,
        .step = &stepMat,
        .size = &sizeMat,
    };
}

void matToCV_Mat(Mat& exMat, cv::Mat& mat) {
    int* sizes = new int[2] {exMat.height, exMat.width};
    mat = cv::Mat(exMat.dimentions, sizes, CV_8UC(exMat.channels), exMat.data).clone();
}
