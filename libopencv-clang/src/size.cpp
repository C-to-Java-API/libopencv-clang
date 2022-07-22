//
//  size.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 21.07.2022.
//

#include "include/size_type.h"

#include "opencv2/core/mat.hpp"


int area(Size& s) {
    return cv::Size(s.width, s.height).area();
}

bool empty(Size& s) {
    return cv::Size(s.width, s.height).empty();
}

double aspectRatio(Size& s) {
    return cv::Size(s.width, s.height).aspectRatio();
}

int size(Size& src, Size& dst) {
    auto intermediate = cv::Size(src.width, src.height);
    if (intermediate.empty()) {
        return -1;
    }
    dst = {
      .width = src.width,
      .height = src.height
    };
    return 0;
}
