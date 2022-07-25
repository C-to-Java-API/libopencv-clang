//
//  mat.hpp
//  libopencv-clang
//
//  Created by Denis Makogon on 19.07.2022.
//

#ifndef mat_h
#define mat_h

#include "include/mat_type.h"
#include "include/range_type.h"

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

struct Mat row(struct Mat* src, int y);
struct Mat col(struct Mat* src, int x);
struct Mat rowRangeFromStartEnd(struct Mat* src, int startrow, int endrow);
struct Mat rowRangeFromRange(struct Mat* src, const struct Range* r);
struct Mat colRangeFromStartEnd(struct Mat* src, int startcol, int endcol);
struct Mat colRangeFromRange(struct Mat* src, const struct Range* r);
struct Mat diag(struct Mat* src, int d);
struct Mat clone(struct Mat* src);

#endif /* mat_h */
