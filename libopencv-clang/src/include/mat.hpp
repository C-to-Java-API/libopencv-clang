//
//  mat.hpp
//  libopencv-clang
//
//  Created by Denis Makogon on 19.07.2022.
//

#ifndef mat_h
#define mat_h

#include "include/mat_type.h"

struct Mat mat();
struct Mat matAsCopy(const struct Mat* src);
struct Mat matFromColsRowsType(int rows, int cols, int type);
struct Mat matAsNdimentionType(int ndims, const int *sizes, int type);
struct Mat matFromColsRowsTypeAndData(int rows, int cols, int type, void* data);
struct Mat matAsNdimentionTypeAndData(int ndims, const int *sizes, int type, void* data);

struct Mat matFromSizeAndType(struct Size* size, int type);

struct Mat matFromRowRangeColRange(const struct Mat* src, const struct Range* rowRange, const struct Range* colRange);
struct Mat matFromRange(struct Mat* src, const struct Range* roi);
struct Mat matFromRanges(struct Mat* src, const struct Range* ranges[]);

#endif /* mat_h */
