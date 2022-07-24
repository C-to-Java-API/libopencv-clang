//
//  test_mat.cpp
//  libopencv-clang
//
//  Created by Denis Makogon on 19.07.2022.
//

#include "include/mat_type.h"
#include "include/size_type.h"

#include "include/mat.hpp"

#include "opencv2/core/hal/interface.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
    Mat m1, m2, m3, m4, m5, m6;
    int cols = 100;
    int rows = 100;
    int dims[2] = {cols, rows};
    auto s = (Size) {
        .height = rows,
        .width = cols,
    };

    m1 = mat();
    m2 = matFromColsRowsType(cols, rows, CV_8UC3);
    m3 = matAsNdimentionType(2, dims, CV_8UC3);
    m4 = matFromColsRowsTypeAndData(rows, cols, CV_8UC3, m1.data);
    m5 = matAsNdimentionTypeAndData(2, dims, CV_8UC3, m1.data);
    m6 = matFromSizeAndType(&s, 0);
    
    puts("Done with test [mat].");
}
