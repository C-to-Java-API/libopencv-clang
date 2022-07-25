//
//  mat_methods.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#include "include/mat_type.h"
#include "include/size_type.h"
#include "include/range_type.h"
#include "include/export.hpp"

#include "opencv2/core/mat.hpp"

struct Mat _matFunction(
        struct Mat* src, std::function<cv::Mat(cv::Mat)>& proc) {
    cv::Mat cv_m;
    struct Mat m;
    matToCV_Mat(*src, cv_m);
    auto tmp = proc(cv_m);
    CV_MatToMat(tmp, m);
    return m;
}

void _voidFunction(struct Mat* src, std::function<void(cv::Mat)>& proc) {
    cv::Mat cv_src;
    matToCV_Mat(*src, cv_src);
    proc(cv_src);
    CV_MatToMat(cv_src, *src);
}

bool _boolFunction(struct Mat* src, std::function<bool(cv::Mat)>& proc) {
    cv::Mat cv_src;
    matToCV_Mat(*src, cv_src);
    return proc(cv_src);
}

size_t _sizeTFunction(struct Mat* src, std::function<size_t(cv::Mat)>& proc) {
    cv::Mat cv_src;
    matToCV_Mat(*src, cv_src);
    return proc(cv_src);
}

int _intFunction(struct Mat* src, std::function<int(cv::Mat)>& proc) {
    cv::Mat cv_src;
    matToCV_Mat(*src, cv_src);
    return proc(cv_src);
}

struct Mat row(struct Mat* src, int y) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.row(y);
    };
    return _matFunction(src, fn);
}

struct Mat col(struct Mat* src, int x) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.col(x);
    };
    return _matFunction(src, fn);
}

struct Mat rowRangeFromStartEnd(struct Mat* src, int startrow, int endrow) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.rowRange(startrow, endrow);
    };
    return _matFunction(src, fn);
}

struct Mat rowRangeFromRange(struct Mat* src, const struct Range* r) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.rowRange(cv::Range(r->start, r->end));
    };
    return _matFunction(src, fn);
}

struct Mat colRangeFromStartEnd(struct Mat* src, int startcol, int endcol) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.colRange(startcol, endcol);
    };
    return _matFunction(src, fn);
}

struct Mat colRangeFromRange(struct Mat* src, const struct Range* r) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.colRange(cv::Range(r->start, r->end));
    };
    return _matFunction(src, fn);
}

struct Mat diag(struct Mat* src, int d) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.diag(d);
    };
    return _matFunction(src, fn);
}

struct Mat clone(struct Mat* src) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.clone();
    };
    return _matFunction(src, fn);
}

void assignTo(struct Mat* src, struct Mat* dst, int type) {
    cv::Mat cv_src, cv_dst;
    matToCV_Mat(*src, cv_src);
    cv_src.assignTo(cv_dst, type);
    CV_MatToMat(cv_dst, *dst);
}

struct Mat reshape(struct Mat* src, int cn, int rows) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.reshape(cn, rows);
    };
    return _matFunction(src, fn);
}

struct Mat reshapeWithNewDimentions(struct Mat* src, int cn, int newndims, const int* newsz) {
    std::function<cv::Mat(cv::Mat)> fn = [&](cv::Mat m) {
        return m.reshape(cn, newndims, newsz);
    };
    return _matFunction(src, fn);
}

void createFromColsRowsType(struct Mat* src, int rows, int cols, int type) {
    std::function<void(cv::Mat)> fn = [&](cv::Mat m) {
        m.create(rows, cols, type);
    };
    _voidFunction(src, fn);
}

void createFromSizeAndType(struct Mat* src, struct Size* size, int type) {
    std::function<void(cv::Mat)> fn = [&](cv::Mat m) {
        m.create(cv::Size(size->width, size->height), type);
    };
    _voidFunction(src, fn);
}

void createAsNdimentionType(struct Mat* src, int ndims, const int* sizes, int type) {
    std::function<void(cv::Mat)> fn = [&](cv::Mat m) {
        m.create(ndims, sizes, type);
    };
    _voidFunction(src, fn);
}

void addref(struct Mat* src) {
    std::function<void(cv::Mat)> fn = [&](cv::Mat m) {
        m.addref();
    };
    _voidFunction(src, fn);
}

void release(struct Mat* src) {
    std::function<void(cv::Mat)> fn = [&](cv::Mat m) {
        m.release();
    };
    _voidFunction(src, fn);
}

void push_back(struct Mat* where, struct Mat* what) {
    cv::Mat cv_where, cv_what;
    matToCV_Mat(*where, cv_where);
    matToCV_Mat(*what, cv_what);

    cv_where.push_back(cv_what);

    CV_MatToMat(cv_where, *where);
}

void pop_back(struct Mat* src, size_t nelems) {
    std::function<void(cv::Mat)> fn = [&](cv::Mat m) {
        m.pop_back(nelems);
    };
    _voidFunction(src, fn);
}

bool isContinuous(struct Mat* src) {
    std::function<bool(cv::Mat)> fn = [&](cv::Mat m) {
        return m.isContinuous();
    };
    return _boolFunction(src, fn);
}

bool isSubmatrix(struct Mat* src) {
    std::function<bool(cv::Mat)> fn = [&](cv::Mat m) {
        return m.isSubmatrix();
    };
    return _boolFunction(src, fn);
}

size_t elemSize(struct Mat* src) {
    std::function<size_t(cv::Mat)> fn = [&](cv::Mat m) {
        return m.elemSize();
    };
    return _sizeTFunction(src, fn);
}

size_t elemSize1(struct Mat* src) {
    std::function<size_t(cv::Mat)> fn = [&](cv::Mat m) {
        return m.elemSize1();
    };
    return _sizeTFunction(src, fn);
}

int type(struct Mat* src) {
    std::function<int(cv::Mat)> fn = [&](cv::Mat m) {
        return m.type();
    };
    return _intFunction(src, fn);
}

int depth(struct Mat* src) {
    std::function<int(cv::Mat)> fn = [&](cv::Mat m) {
        return m.depth();
    };
    return _intFunction(src, fn);
}

int channels(struct Mat* src) {
    std::function<int(cv::Mat)> fn = [&](cv::Mat m) {
        return m.channels();
    };
    return _intFunction(src, fn);
}

size_t step1(struct Mat* src, int i) {
    std::function<size_t(cv::Mat)> fn = [&](cv::Mat m) {
        return m.step1();
    };
    return _sizeTFunction(src, fn);
}

bool matIsEmpty(struct Mat* src) {
    std::function<bool(cv::Mat)> fn = [&](cv::Mat m) {
        return m.empty();
    };
    return _boolFunction(src, fn);
}

size_t total(struct Mat* src) {
    std::function<size_t(cv::Mat)> fn = [&](cv::Mat m) {
        return m.total();
    };
    return _sizeTFunction(src, fn);
}

size_t totalWithinDimentions(struct Mat* src, int startDim, int endDim) {
    std::function<size_t(cv::Mat)> fn = [&](cv::Mat m) {
        return m.total(startDim, endDim);
    };
    return _sizeTFunction(src, fn);
}

int checkVector(struct Mat* src, int elemChannels, int depth, bool requireContinuous) {
    std::function<int(cv::Mat)> fn = [&](cv::Mat m) {
        return m.checkVector(elemChannels, depth, requireContinuous);
    };
    return _intFunction(src, fn);
}
