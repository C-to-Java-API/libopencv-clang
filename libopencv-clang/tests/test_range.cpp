//
//  test_range.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 24.07.2022.
//

#include <stdio.h>
#include <limits.h>

#include <cassert>

#include "include/range_type.h"
#include "include/range.hpp"

int main(int argc, char* argv[]) {
    auto defaultRange = range();
    auto customRange = rangeStartEnd(1, 10);
    auto allRange = all();
    
    auto sizeOfDefaultRange = size(&defaultRange);
    auto sizeOfCustomRange = size(&customRange);
    auto sizeOfAllRange = size(&allRange);
    
    assert(sizeOfDefaultRange == 0);
    assert(sizeOfCustomRange == 9);
    assert(sizeOfAllRange == -1);
    
    puts("Done with test [range].");
}
