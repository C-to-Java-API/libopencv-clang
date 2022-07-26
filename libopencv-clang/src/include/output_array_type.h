//
//  output_array_type.h
//  libopencv-clang
//
//  Created by Denis Makogon on 26.07.2022.
//

#ifndef output_array_type_h
#define output_array_type_h

#include "include/input_array_type.h"

#include "opencv2/core/hal/interface.h"

typedef enum {
    DEPTH_MASK_8U = 1 << CV_8U,
    DEPTH_MASK_8S = 1 << CV_8S,
    DEPTH_MASK_16U = 1 << CV_16U,
    DEPTH_MASK_16S = 1 << CV_16S,
    DEPTH_MASK_32S = 1 << CV_32S,
    DEPTH_MASK_32F = 1 << CV_32F,
    DEPTH_MASK_64F = 1 << CV_64F,
    DEPTH_MASK_16F = 1 << CV_16F,
    DEPTH_MASK_ALL = (DEPTH_MASK_64F<<1)-1,
    DEPTH_MASK_ALL_BUT_8S = DEPTH_MASK_ALL & ~DEPTH_MASK_8S,
    DEPTH_MASK_ALL_16F = (DEPTH_MASK_16F<<1)-1,
    DEPTH_MASK_FLT = DEPTH_MASK_32F + DEPTH_MASK_64F
} DepthMask;

typedef struct InputArray OutputArray;

#endif /* output_array_type_h */
