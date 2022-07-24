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
struct Mat mat() {
    Mat cv_m;
    auto m = cv::Mat();
    CV_MatToMat(m, cv_m);
    return cv_m;
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - rows,
 - cols,
 - type.
 The equivalent of cv::Mat(int rows, int cols, int type)
 */
struct Mat matFromColsRowsType(int rows, int cols, int type) {
    Mat cv_m;
    auto m = cv::Mat(rows, cols, type);
    CV_MatToMat(m, cv_m);
    return cv_m;
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - rows,
 - cols,
 - type,
 - data.
 The equivalent of cv::Mat(int rows, int cols, int type, void* data)
 */
struct Mat matFromColsRowsTypeAndData(int rows, int cols, int type, void* data) {
    Mat cv_m;
    auto m = cv::Mat(rows, cols, type, data);
    CV_MatToMat(m, cv_m);
    return cv_m;
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - ndims,
 - sizes,
 - type.
 The equivalent of cv::Mat(int ndims, const int *sizes, int type)
 */
struct Mat matAsNdimentionType(int ndims, const int *sizes, int type) {
    Mat cv_m;
    auto m = cv::Mat(ndims, sizes, type);
    CV_MatToMat(m, cv_m);
    return cv_m;
}

/*
 Creates an OpenCV matrix based on the particular attributes:
 - ndims,
 - sizes,
 - type,
 - data.
 The equivalent of cv::Mat(int ndims, const int *sizes, int type, void* data)
 */
struct Mat matAsNdimentionTypeAndData(int ndims, const int *sizes, int type, void* data) {
    Mat cv_m;
    auto m = cv::Mat(ndims, sizes, type, data);
    CV_MatToMat(m, cv_m);
    return cv_m;
}

/*
 Creates a copy of an OpenCV matrix
 The equivalent of cv::Mat(const cv::Mat copyOf)
 */
struct Mat matAsCopy(struct Mat* src) {
    return {
        .data = src->data,
        .width = src->width,
        .height = src->height,
        .channels = src->channels,
        .flags = src->flags,
        .dimentions = src->dimentions,
        .datastart = src->datastart,
        .dataend = src->dataend,
        .datalimit = src->datalimit,
        .step = src->step,
        .size = src->size,
    };
}

struct Mat matFromSizeAndType(struct Size* size, int type) {
    Mat cv_m;
    auto s = cv::Size(size->width, size->height);
    auto m = cv::Mat(s, type);
    CV_MatToMat(m, cv_m);
    return cv_m;
}
