//
//  rect.h
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#ifndef rect_h
#define rect_h

#include "include/point_type.h"
#include "include/rect_type.h"
#include "include/size_type.h"

struct Rect rect();
struct Rect rectWithArgs(int x, int y, int width, int height);
struct Rect rectFromRect(struct Rect* rect);
struct Rect rectFromPointSize(struct Point* p, struct Size* s);
struct Rect rectFromPoints(struct Point* p1, struct Point* p2);

struct Point tl(struct Rect* src);
struct Point br(struct Rect* src);

struct Size sizeOfRect(struct Rect* src);

long areaOfRect(struct Rect* src);
bool rectIsEmpty(struct Rect* src);
bool contains(struct Rect* where, struct Point* what);

#endif /* rect_h */
