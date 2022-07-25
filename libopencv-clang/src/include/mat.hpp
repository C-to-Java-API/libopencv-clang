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

void assignTo(struct Mat* src, struct Mat* dst, int type);
struct Mat reshape(struct Mat* src, int cn, int rows);
struct Mat reshapeWithNewDimentions(struct Mat* src, int cn, int newndims, const int* newsz);
void createFromColsRowsType(struct Mat* src, struct Mat* dst, int rows, int cols, int type);
void createFromSizeAndType(struct Mat* src, struct Mat* dst, struct Size* size, int type);
void createAsNdimentionType(struct Mat* src, struct Mat* dst, int ndims, const int* sizes, int type);
void addref(struct Mat* src);
void release(struct Mat* src);
void push_back(struct Mat* where, struct Mat* what);
void pop_back(struct Mat* src, size_t nelems);
bool isContinuous(struct Mat* src);
bool isSubmatrix(struct Mat* src);
size_t elemSize(struct Mat* src);
size_t elemSize1(struct Mat* src);
int type(struct Mat* src);
int depth(struct Mat* src);
int channels(struct Mat* src);
size_t step1(struct Mat* src, int i);
bool matIsEmpty(struct Mat* src);
size_t total(struct Mat* src);
size_t totalWithinDimentions(struct Mat* src, int startDim, int endDim);
int checkVector(struct Mat* src, int elemChannels, int depth, bool requireContinuous);

#endif /* mat_h */
