//
//  point.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#include "include/point_type.h"
#include "include/size_type.h"

#include "opencv2/core/types.hpp"


struct Point point() {
    auto p = cv::Point();
    return {
        .x = p.x,
        .y = p.y,
    };
}

struct Point pointWithXY(int x, int y) {
    auto p = cv::Point(x, y);
    return {
        .x = p.x,
        .y = p.y,
    };
}

struct Point pointFromPoint(struct Point* p) {
    auto pp = cv::Point(cv::Point(p->x, p->y));
    return {
        .x = pp.x,
        .y = pp.y,
    };
}

struct Point pointFromSize(struct Size* s) {
    auto ps = cv::Point(cv::Size(s->width, s->height));
    return {
        .x = ps.x,
        .y = ps.y,
    };
}

long pointDot(struct Point* src, struct Point* prod) {
    auto p_src = cv::Point(src->x, src->y);
    auto p_prod = cv::Point(prod->x, prod->y);
    return p_src.dot(p_prod);
}

double pointDdot(struct Point* src, struct Point* prod) {
    auto p_src = cv::Point(src->x, src->y);
    auto p_prod = cv::Point(prod->x, prod->y);
    return p_src.ddot(p_prod);
}

double pointCross(struct Point* src, struct Point* prod) {
    auto p_src = cv::Point(src->x, src->y);
    auto p_prod = cv::Point(prod->x, prod->y);
    return p_src.cross(p_prod);
}
