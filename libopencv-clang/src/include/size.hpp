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
bool empty(struct Size* s);
double aspectRatio(struct Size* s);
int size(struct Size* src, struct Size* dst);

#endif /* size_h */
