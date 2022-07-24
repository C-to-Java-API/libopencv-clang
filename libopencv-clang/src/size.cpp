//
//  size.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 21.07.2022.
//

#include "include/size_type.h"

#include "opencv2/core/types.hpp"


int area(struct Size* s) {
    return cv::Size(s->width, s->height).area();
}

bool empty(struct Size* s) {
    return cv::Size(s->width, s->height).empty();
}

double aspectRatio(struct Size* s) {
    return cv::Size(s->width, s->height).aspectRatio();
}


struct Size size() {
    auto s = cv::Size();
    return {
        .width = s.width,
        .height = s.height
    };
}

struct Size sizeAsCopy(struct Size* src) {
    auto intermediate = cv::Size(src->width, src->height);
    return {
      .width = intermediate.width,
      .height = intermediate.height
    };
}
