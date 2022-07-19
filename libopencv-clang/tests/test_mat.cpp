//
//  test_mat.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 19.07.2022.
//

#include "include/mat_type.h"
#include "include/mat.hpp"

#include <stdio.h>

int main(int argc, char* argv[]) {
    Mat m;
    
    mat(&m);
    
    Mat dest;
    matAsCopy(&m, &dest);
    
//    mat
    
    puts("Done with test [mat].");
}
