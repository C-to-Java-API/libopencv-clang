//
//  point.hpp
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#ifndef point_h
#define point_h

#include "include/point_type.h"

struct Point point();
struct Point pointWithXY(int x, int y);
struct Point pointFromPoint(struct Point* p);
struct Point pointFromSize(struct Size* s);
long pointDot(struct Point* src, struct Point* prod);
double pointDdot(struct Point* src, struct Point* prod);
double pointCross(struct Point* src, struct Point* prod);

#endif /* point_h */
