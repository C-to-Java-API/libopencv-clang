//
//  mat_methods.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#include "include/mat_type.h"
#include "include/range_type.h"
#include "include/export.hpp"

#include "opencv2/core/mat.hpp"

struct Mat _processWithFunction(
        struct Mat* src, std::function<cv::Mat(cv::Mat)>& proc) {
    cv::Mat cv_m;
    struct Mat m;
    matToCV_Mat(*src, cv_m);
    
    auto tmp = proc(cv_m);
    
    CV_MatToMat(tmp, m);
    
    return m;
}

struct Mat row(struct Mat* src, int y) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.row(y);
    };
    return _processWithFunction(src, fn);
}

struct Mat col(struct Mat* src, int x) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.col(x);
    };
    return _processWithFunction(src, fn);
}

struct Mat rowRangeFromStartEnd(struct Mat* src, int startrow, int endrow) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.rowRange(startrow, endrow);
    };
    return _processWithFunction(src, fn);
}

struct Mat rowRangeFromRange(struct Mat* src, const struct Range* r) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.rowRange(cv::Range(r->start, r->end));
    };
    return _processWithFunction(src, fn);
}

struct Mat colRangeFromStartEnd(struct Mat* src, int startcol, int endcol) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.colRange(startcol, endcol);
    };
    return _processWithFunction(src, fn);
}

struct Mat colRangeFromRange(struct Mat* src, const struct Range* r) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.colRange(cv::Range(r->start, r->end));
    };
    return _processWithFunction(src, fn);
}

struct Mat diag(struct Mat* src, int d) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.diag(d);
    };
    return _processWithFunction(src, fn);
}

struct Mat clone(struct Mat* src) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.clone();
    };
    return _processWithFunction(src, fn);
}
