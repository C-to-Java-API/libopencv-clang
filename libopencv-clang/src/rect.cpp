//
//  rect.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#include "include/point_type.h"
#include "include/rect_type.h"
#include "include/size_type.h"

#include "opencv2/core/types.hpp"


struct Rect rect() {
    auto r = cv::Rect();
    return {
        .x = r.x,
        .y = r.y,
        .height = r.height,
        .width = r.width,
    };
}

struct Rect rectWithArgs(int x, int y, int width, int height) {
    auto r = cv::Rect(x, y, width, height);
    return {
        .x = r.x,
        .y = r.y,
        .height = r.height,
        .width = r.width,
    };
}

struct Rect rectFromRect(struct Rect* rect) {
    auto rr = cv::Rect(cv::Rect(rect->x, rect->y, rect->width, rect->height));
    return {
        .x = rr.x,
        .y = rr.y,
        .height = rr.height,
        .width = rr.width,
    };
}

struct Rect rectFromPointSize(struct Point* p, struct Size* s) {
    auto rr = cv::Rect(cv::Point(p->x, p->y), cv::Size(s->width, s->height));
    return {
        .x = rr.x,
        .y = rr.y,
        .height = rr.height,
        .width = rr.width,
    };
}

struct Rect rectFromPoints(struct Point* p1, struct Point* p2) {
    auto rr = cv::Rect(cv::Point(p1->x, p1->y), cv::Point(p2->x, p2->y));
    return {
        .x = rr.x,
        .y = rr.y,
        .height = rr.height,
        .width = rr.width,
    };
}

struct Point tl(struct Rect* src) {
    auto tl_ = cv::Rect(src->x, src->y, src->width, src->height).tl();
    return {
        .x = tl_.x,
        .y = tl_.y,
    };
}

struct Point br(struct Rect* src) {
    auto br_ = cv::Rect(src->x, src->y, src->width, src->height).br();
    return {
        .x = br_.x,
        .y = br_.y,
    };
}

struct Size sizeOfRect(struct Rect* src) {
    auto s_ = cv::Rect(src->x, src->y, src->width, src->height).size();
    return {
        .width = s_.width,
        .height = s_.height,
    };
}

long areaOfRect(struct Rect* src) {
    return cv::Rect(src->x, src->y, src->width, src->height).area();
}

bool rectIsEmpty(struct Rect* src) {
    return cv::Rect(src->x, src->y, src->width, src->height).empty();
}

bool contains(struct Rect* where, struct Point* what) {
    return cv::Rect(where->x, where->y, where->width, where->height)
        .contains(cv::Point(what->x, what->y));
}
