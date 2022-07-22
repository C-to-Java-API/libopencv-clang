//
//  mat.cpp
//  javacv
//
//  Created by Denis Makogon on 18.07.2022.
//

#include "include/mat_type.h"
#include "include/size_type.h"
#include "include/export.hpp"

#include "opencv2/core/mat.hpp"

/*
 Note: C does not allow method overloading, so we'd have to introduce unique names!
*/

// Creates the default OpenCV matrix, the equivalent of cv::Mat()
void mat(struct Mat* cv_m) {
    auto m = cv::Mat();
    CV_MatToMat(m, *cv_m);
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - rows,
 - cols,
 - type.
 The equivalent of cv::Mat(int rows, int cols, int type)
 */
void matFromColsRowsType(struct Mat* cv_m, int rows, int cols, int type) {
    auto m = cv::Mat(rows, cols, type);
    CV_MatToMat(m, *cv_m);
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - rows,
 - cols,
 - type,
 - data.
 The equivalent of cv::Mat(int rows, int cols, int type, void* data)
 */
void matFromColsRowsTypeAndData(struct Mat* cv_m, int rows, int cols, int type, void* data) {
    auto m = cv::Mat(rows, cols, type, data);
    CV_MatToMat(m, *cv_m);
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - ndims,
 - sizes,
 - type.
 The equivalent of cv::Mat(int ndims, const int *sizes, int type)
 */
void matAsNdimentionType(struct Mat* cv_m, int ndims, const int *sizes, int type) {
    auto m = cv::Mat(ndims, sizes, type);
    CV_MatToMat(m, *cv_m);
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - ndims,
 - sizes,
 - type,
 - data.
 The equivalent of cv::Mat(int ndims, const int *sizes, int type, void* data)
 */
void matAsNdimentionTypeAndData(struct Mat* cv_m, int ndims, const int *sizes, int type, void* data) {
    auto m = cv::Mat(ndims, sizes, type, data);
    CV_MatToMat(m, *cv_m);
}

/*
 Creates a copy of an OpenCV matrix
 The equivalent of cv::Mat(const cv::Mat copyOf)
 */
void matAsCopy(const struct Mat* src, struct Mat* dest) {
    struct Mat tmp = {
        .data = src->data,
        .width = src->width,
        .height = src->height,
        .channels = src->channels,
        .flags = src->flags,
        .dimentions = src->dimentions,
    };
    dest = &tmp;
}

void matFromSizeAndType(struct Mat* cv_m, struct Size* size, int type) {
    auto s = cv::Size(size->width, size->height);
    auto m = cv::Mat(s, type);
    CV_MatToMat(m, *cv_m);
}
