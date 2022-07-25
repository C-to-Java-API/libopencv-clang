//
//  range.hpp
//  libopencv-clang
//
//  Created by Denis Makogon on 24.07.2022.
//

#ifndef range_hpp
#define range_hpp

#include "include/range_type.h"

struct Range range();
struct Range rangeStartEnd(const int start, const int end);

int sizeOfRange(struct Range* range);
bool rangeIsEmpty(struct Range* range);
struct Range all();


#endif /* range_hpp */
