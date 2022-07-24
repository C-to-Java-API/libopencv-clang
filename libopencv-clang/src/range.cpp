//
//  range.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 24.07.2022.
//

/*
  static Range all();

  int start, end;
*/

#include "include/range_type.h"

#include "opencv2/core/types.hpp"

struct Range range() {
    auto range = cv::Range();
    return {
        .start = range.start,
        .end = range.end,
    };
}

struct Range rangeStartEnd(const int start, const int end) {
    auto range = cv::Range(start, end);
    return {
        .start = range.start,
        .end = range.end,
    };
}

int size(struct Range* range) {
    return cv::Range(range->start, range->end).size();
}

bool empty(struct Range* range) {
    return cv::Range(range->start, range->end).empty();
}

struct Range all() {
    auto r = cv::Range::all();
    return {
        .start = r.start,
        .end = r.end,
    };
}
