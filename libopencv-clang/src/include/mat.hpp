//
//  mat.hpp
//  libopencv-clang
//
//  Created by Denis Makogon on 19.07.2022.
//

#ifndef mat_h
#define mat_h

#include "include/mat_type.h"

void mat(struct Mat* cv_m);
void matAsCopy(struct Mat* src, struct Mat* dest);
void matFromColsRowsType(struct Mat* cv_m, int rows, int cols, int type);
void matAsNdimentionType(struct Mat* cv_m, int ndims, const int *sizes, int type);
void matFromColsRowsTypeAndData(struct Mat* cv_m, int rows, int cols, int type, void* data);
void matAsNdimentionTypeAndData(struct Mat* cv_m, int ndims, const int *sizes, int type, void* data);

void matFromSizeAndType(struct Mat* cv_m, struct Size* size, int type);


#endif /* mat_h */
