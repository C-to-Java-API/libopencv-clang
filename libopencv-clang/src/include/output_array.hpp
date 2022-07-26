//
//  output_array.h
//  libopencv-clang
//
//  Created by Denis Makogon on 26.07.2022.
//

#ifndef output_array_h
#define output_array_h

#include "include/mat_type.h"
#include "include/size_type.h"
#include "include/output_array_type.h"

OutputArray outputArray();
OutputArray outputArrayWithParameters(int _flags, void* _obj);
OutputArray fromMat(struct Mat* m);
OutputArray fromMatArray(struct Mat* m[]);

bool fixedSize(OutputArray* src);
bool fixedType(OutputArray* src);
bool needed(OutputArray* src);

struct Mat getMatRef(OutputArray* src, int i);

void createFromSize(OutputArray* src, struct Size* sz, int type, int i, bool allowTransposed, DepthMask fixedDepthMask);
void createFromRowCols(OutputArray* src, int rows, int cols, int type, int i, bool allowTransposed, DepthMask fixedDepthMask);
void createFromNdimentions(OutputArray* src, int dims, const int* size, int type, int i, bool allowTransposed, DepthMask fixedDepthMask);
void createSameSize(OutputArray* src, const struct InputArray* arr, int mtype);
void outputArrayRelease(OutputArray* src);
void clear(OutputArray* src);
void outputArraySetTo(OutputArray* src, const struct InputArray* value, struct InputArray* mask);

void assignMat(OutputArray* src, const struct Mat* m);
void assignMatArray(OutputArray* src, struct Mat* arr[]);

void move(OutputArray* src, struct Mat* m);

#endif /* output_array_h */
