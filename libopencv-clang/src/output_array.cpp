//
//  output_array.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 26.07.2022.
//

#include <stdlib.h>

#include "include/mat_type.h"
#include "include/size_type.h"
#include "include/output_array_type.h"

#include "include/export.hpp"

#include "opencv2/core/mat.hpp"


OutputArray _construct(std::function< cv::OutputArray() > proc) {
    auto cv_oa = proc();
    OutputArray r;
    CV_OutputArrayToOutputArray(cv_oa, &r);
    return r;
}

OutputArray outputArray() {
    std::function< cv::OutputArray() > fn = [&] () {
        return cv::_OutputArray();
    };
    return _construct(fn);
}

OutputArray outputArrayWithParameters(int _flags, void* _obj) {
    std::function< cv::OutputArray() > fn = [&] () {
        return cv::_OutputArray(_flags, _obj);
    };
    return _construct(fn);
}

OutputArray fromMat(struct Mat* m) {
    std::function< cv::OutputArray() > fn = [&] () {
        cv::Mat cv_m;
        matToCV_Mat(*m, cv_m);
        return cv::_OutputArray(cv_m);
    };
    return _construct(fn);
}

OutputArray fromMatArray(struct Mat* m[]) {
    std::function< cv::OutputArray() > fn = [&] () {
        std::vector<cv::Mat> vt;
        int nM = sizeof(&m)/sizeof(&m[0]);
        cv::Mat cv_m;
        for (int i = 0; i < nM; i++) {
            matToCV_Mat(*m[i], cv_m);
            vt.push_back(cv_m);
        }
        return cv::_OutputArray(vt);
    };
    return _construct(fn);
}

bool fixedSize(OutputArray* src) {
    return cv::_OutputArray(src->flags, src->obj).fixedSize();
}

bool fixedType(OutputArray* src) {
    return cv::_OutputArray(src->flags, src->obj).fixedType();
}

bool needed(OutputArray* src) {
    return cv::_OutputArray(src->flags, src->obj).needed();
}

struct Mat getMatRef(OutputArray* src, int i) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    cv::Mat cv_m = cv_oa.getMatRef();
    struct Mat m;
    CV_MatToMat(cv_m, m);
    return m;
}

void createFromSize(OutputArray* src, struct Size* sz, int type,
                    int i, bool allowTransposed, DepthMask fixedDepthMask) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    auto mask = static_cast<cv::_OutputArray::DepthMask>(fixedDepthMask);
    cv_oa.create(cv::Size(sz->width, sz->height), type, i, allowTransposed, mask);
    CV_OutputArrayToOutputArray(cv_oa, src);
}

void createFromRowCols(OutputArray* src, int rows, int cols, int type,
                       int i, bool allowTransposed, DepthMask fixedDepthMask) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    auto mask = static_cast<cv::_OutputArray::DepthMask>(fixedDepthMask);
    cv_oa.create(rows, cols, type, i, allowTransposed, mask);
    CV_OutputArrayToOutputArray(cv_oa, src);
}

void createFromNdimentions(OutputArray* src, int dims, const int* size, int type, int i, bool allowTransposed, DepthMask fixedDepthMask) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    auto mask = static_cast<cv::_OutputArray::DepthMask>(fixedDepthMask);
    cv_oa.create(dims, size, type, i, allowTransposed, mask);
    CV_OutputArrayToOutputArray(cv_oa, src);
}

void createSameSize(OutputArray* src, const struct InputArray* arr, int mtype) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    cv::InputArray cv_ir = cv::_InputArray(arr->flags, arr->obj);
    cv_oa.createSameSize(cv_ir, mtype);
    CV_OutputArrayToOutputArray(cv_oa, src);
}

void outputArrayRelease(OutputArray* src) {
    cv::_OutputArray(src->flags, src->obj).release();
    src = NULL;
}

void clear(OutputArray* src) {
    cv::_OutputArray(src->flags, src->obj).clear();
    CV_OutputArrayToOutputArray(cv::_OutputArray(), src);
}

void outputArraySetTo(OutputArray* src, const struct InputArray* value, struct InputArray* mask) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    cv::InputArray cv_value = cv::_InputArray(value->flags, value->obj);
    cv::InputArray cv_mask = cv::_InputArray(mask->flags, mask->obj);
    cv_oa.setTo(cv_value, cv_mask);
    CV_OutputArrayToOutputArray(cv_oa, src);
}

void assignMat(OutputArray* src, const struct Mat* m) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    cv::Mat cv_m;
    struct Mat* mm = (struct Mat*) m;
    matToCV_Mat(*mm, cv_m);
    cv_oa.assign(cv_m);
    CV_OutputArrayToOutputArray(cv_oa, src);
}

void assignMatArray(OutputArray* src, struct Mat* arr[]) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    std::vector<cv::Mat> vt;
    int nM = sizeof(&arr)/sizeof(&arr[0]);
    cv::Mat cv_m;
    for (int i = 0; i < nM; i++) {
        matToCV_Mat(*arr[i], cv_m);
        vt.push_back(cv_m);
    }
    cv_oa.assign(vt);
    CV_OutputArrayToOutputArray(cv_oa, src);
}

void move(OutputArray* src, struct Mat* m) {
    cv::OutputArray cv_oa = cv::_OutputArray(src->flags, src->obj);
    cv::Mat cv_m;
    matToCV_Mat(*m, cv_m);
    cv_oa.move(cv_m);
    CV_OutputArrayToOutputArray(cv_oa, src);
}
