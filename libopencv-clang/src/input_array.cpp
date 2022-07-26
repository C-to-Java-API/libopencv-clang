//
//  input_array.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#include <stdlib.h>

#include "include/mat_type.h"
#include "include/size_type.h"
#include "include/input_array_type.h"

#include "include/export.hpp"

#include "opencv2/core/mat.hpp"


void CV_InputArrayToInputArray(struct InputArray* dst, cv::InputArray& src) {
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

struct InputArray inputArray() {
    cv::InputArray cv_ir = cv::_InputArray();
    struct InputArray dst;
    CV_InputArrayToInputArray(&dst, cv_ir);
    return dst;
}

struct InputArray inputArrayWithArgs(int _flags, void* _obj) {
    cv::InputArray cv_ir = cv::_InputArray(_flags, _obj);
    struct InputArray dst;
    CV_InputArrayToInputArray(&dst, cv_ir);
    return dst;
}

struct InputArray inputArrayFromMat(struct Mat* src) {
    cv::Mat m;
    matToCV_Mat(*src, m);
    cv::InputArray cv_ir = cv::_InputArray(m);
    struct InputArray dst;
    CV_InputArrayToInputArray(&dst, cv_ir);
    return dst;
}

struct InputArray inputArrayFromMats(struct Mat* srcs[]) {
    long numberOfElements = sizeof(&srcs)/sizeof(srcs[0]);
    std::vector<cv::Mat> vt(numberOfElements);
    for(int i = 0; i < numberOfElements; i++) {
        cv::Mat m;
        matToCV_Mat(*srcs[i], m);
        vt.push_back(m);
    }
    cv::InputArray cv_ir = cv::_InputArray(vt);
    struct InputArray dst;
    CV_InputArrayToInputArray(&dst, cv_ir);
    return dst;
}

struct InputArray inputArrayFromBool(bool* arr[]) {
    long numberOfElements = sizeof(&arr)/sizeof(arr[0]);
    std::vector<bool> src(*arr, *arr + numberOfElements);
    cv::InputArray cv_ir = cv::_InputArray(src);
    struct InputArray dst;
    CV_InputArrayToInputArray(&dst, cv_ir);
    return dst;
}

struct InputArray inputArrayFromDouble(const double* val) {
    cv::InputArray cv_ir = cv::_InputArray(*val);
    struct InputArray dst;
    CV_InputArrayToInputArray(&dst, cv_ir);
    return dst;
}

struct Mat getMat_(struct InputArray* src, int idx) {
    cv::InputArray cv_ir = cv::_InputArray(src->flags, src->obj);
    auto m = cv_ir.getMat(idx);
    struct Mat dst;
    CV_MatToMat(m, dst);
    return dst;
}

struct Mat getMat(struct InputArray* src, int idx) {
    return getMat_(src, idx);
}

void getMatVector(struct InputArray* src, struct Mat* dst) {
    cv::InputArray cv_ir = cv::_InputArray(src->flags, src->obj);
    std::vector<cv::Mat> vt;
    std::vector<struct Mat> res;
    cv_ir.getMatVector(vt);
    for(auto cv_m: vt) {
        struct Mat m;
        CV_MatToMat(cv_m, m);
        res.push_back(m);
    }
    dst = res.data();
}

int getFlags(struct InputArray* src) {
    return cv::_InputArray(src->flags, src->obj).getFlags();
}

void* getObj(struct InputArray* src) {
    return cv::_InputArray(src->flags, src->obj).getObj();
}

struct Size getSz(struct InputArray* src) {
    auto cv_ir = cv::_InputArray(src->flags, src->obj);
    return (Size) {
        .width = cv_ir.getSz().width,
        .height = cv_ir.getSz().height,
    };
}

int dims(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).dims();
}

int cols(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).cols();
}

int rows(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).rows();
}

struct Size sizeOfInputArray(struct InputArray* src, int i) {
    auto cv_ir = cv::_InputArray(src->flags, src->obj);
    auto cv_ir_size = cv_ir.size(i);
    return (Size) {
        .width = cv_ir_size.width,
        .height = cv_ir_size.height,
    };
}

int sizend(struct InputArray* src, int* sz, int i) {
    return cv::_InputArray(src->flags, src->obj).sizend(sz, i);
}

size_t inputArrayTotal(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).total(i);
}

int inputArrayType(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).type(i);
}

int inputArrayDepth(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).depth(i);
}

int inputArrayChannels(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).channels(i);
}

bool inputArrayIsContinuous(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).isContinuous(i);
}

bool inputArrayIsSubmatrix(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).isSubmatrix(i);
}

bool inputArrayIsEmpty(struct InputArray* src) {
    return cv::_InputArray(src->flags, src->obj).empty();
}

size_t offset(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).offset(i);
}

size_t step(struct InputArray* src, int i) {
    return cv::_InputArray(src->flags, src->obj).step(i);
}

bool isMat(struct InputArray* src) {
    return cv::_InputArray(src->flags, src->obj).isMat();
}

bool isMatVector(struct InputArray* src) {
    return cv::_InputArray(src->flags, src->obj).isMatVector();
}
