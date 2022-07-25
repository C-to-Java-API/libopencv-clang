//
//  test_size.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 24.07.2022.
//

#include <stdio.h>

#include <cassert>

#include "include/size_type.h"
#include "include/size.hpp"

int main(int argc, char* argv[]) {
    auto emptySize = size();
    auto asCopyOfEmpty = sizeAsCopy(&emptySize);
    
    auto nonEmpty = (Size) {
        .width = 100,
        .height = 100,
    };
    auto asCopyOfNonEmpty = sizeAsCopy(&nonEmpty);
    
    assert(sizeIsEmpty(&asCopyOfEmpty) == sizeIsEmpty(&emptySize));
    assert(sizeIsEmpty(&asCopyOfNonEmpty) == sizeIsEmpty(&nonEmpty));
    
    puts("Done with test [size].");
}
