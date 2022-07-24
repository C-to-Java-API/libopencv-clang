//
//  range.hpp
//  libopencv-clang
//
//  Created by Denis Makogon on 24.07.2022.
//

#ifndef range_hpp
#define range_hpp

struct Range range();
struct Range rangeStartEnd(const int start, const int end);

int size(struct Range* range);
bool empty(struct Range* range);
struct Range all();


#endif /* range_hpp */
