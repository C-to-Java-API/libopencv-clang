//
//  size.h
//  libopencv-clang
//
//  Created by Denis Makogon on 21.07.2022.
//

#ifndef size_h
#define size_h

#include "include/size_type.h"

int area(struct Size* s);
bool sizeIsEmpty(struct Size* s);
double aspectRatio(struct Size* s);

struct Size size();
struct Size sizeAsCopy(struct Size* src);

#endif /* size_h */
