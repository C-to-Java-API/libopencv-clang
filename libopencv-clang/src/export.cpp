//
//  _export.cpp
//  javacv
//
//  Created by Denis Makogon on 18.07.2022.
//

#include "include/mat_type.h"
#include "include/input_array_type.h"
#include "include/output_array_type.h"

#include "opencv2/core/mat.hpp"

using namespace std;

void CV_MatToMat(cv::Mat& cv_mat, Mat& mat) {
    unsigned long size = cv_mat.total() * cv_mat.elemSize();
    uchar * bytes = new uchar[size];
    memcpy(bytes,cv_mat.data,size * sizeof(uchar));

    auto stepMat = (MatStep) {
        .p = cv_mat.step.p,
        .buf = {*cv_mat.step.buf}
    };
    auto sizeMat = (MatSize) {
        .p = cv_mat.size.p
    };
    
    mat = (Mat) {
        .data = bytes,
        .width = cv_mat.cols,
        .height = cv_mat.rows,
        .channels = cv_mat.channels(),
        .dimentions = cv_mat.dims,
        .flags = cv_mat.flags,
        .datastart = cv_mat.datastart,
        .dataend = cv_mat.dataend,
        .datalimit = cv_mat.datalimit,
        .step = &stepMat,
        .size = &sizeMat,
    };
    cv_mat.release();
}

void matToCV_Mat(Mat& exMat, cv::Mat& mat) {
    int* sizes = new int[2] {exMat.height, exMat.width};
    mat = cv::Mat(exMat.dimentions, sizes, CV_8UC(exMat.channels), exMat.data).clone();
}

void CV_OutputArrayToOutputArray(cv::OutputArray& src, OutputArray* dst) {
    auto s = (Size) {
        .width = src.getSz().width,
        .height = src.getSz().height,
    };
    auto tmp = (OutputArray) {
        .obj = src.getObj(),
        .flags = src.getFlags(),
        .sz = &s,
    };
    src.release();
    dst = &tmp;
}

void CV_InputArrayToInputArray(cv::InputArray& src, struct InputArray* dst) {
    auto s = (Size) {
        .width = src.getSz().width,
        .height = src.getSz().height,
    };
    auto tmp = (InputArray) {
        .obj = src.getObj(),
        .flags = src.getFlags(),
        .sz = &s,
    };
    dst = &tmp;
}
