//
//  input_array_type.h
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#ifndef input_array_type_h
#define input_array_type_h

#include "include/size_type.h"

typedef enum {
    KIND_SHIFT = 16,
    FIXED_TYPE = 0x8000 << KIND_SHIFT,
    FIXED_SIZE = 0x4000 << KIND_SHIFT,
    KIND_MASK = 31 << KIND_SHIFT,
    NONE              = 0 << KIND_SHIFT,
    MAT               = 1 << KIND_SHIFT,
    MATX              = 2 << KIND_SHIFT,
    STD_VECTOR        = 3 << KIND_SHIFT,
    STD_VECTOR_VECTOR = 4 << KIND_SHIFT,
    STD_VECTOR_MAT    = 5 << KIND_SHIFT,
    OPENGL_BUFFER     = 7 << KIND_SHIFT,
    CUDA_HOST_MEM     = 8 << KIND_SHIFT,
    CUDA_GPU_MAT      = 9 << KIND_SHIFT,
    UMAT              =10 << KIND_SHIFT,
    STD_VECTOR_UMAT   =11 << KIND_SHIFT,
    STD_BOOL_VECTOR   =12 << KIND_SHIFT,
    STD_VECTOR_CUDA_GPU_MAT = 13 << KIND_SHIFT,
    STD_ARRAY_MAT     =15 << KIND_SHIFT
} KindFlag;


struct InputArray {
    KindFlag kind;
    
    int flags;
    void* obj;
    struct Size* sz;
};

#endif /* input_array_type_h */
