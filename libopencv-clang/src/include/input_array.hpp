//
//  input_array.hpp
//  libopencv-clang
//
//  Created by Denis Makogon on 25.07.2022.
//

#ifndef input_array_h
#define input_array_h

#include <stdlib.h>

#include "include/mat_type.h"
#include "include/size_type.h"
#include "include/input_array_type.h"

struct InputArray inputArray();
struct InputArray inputArrayWithArgs(int _flags, void* _obj);
struct InputArray inputArrayFromMat(struct Mat* src);
struct InputArray inputArrayFromMats(struct Mat* srcs[]);
struct InputArray inputArrayFromBool(bool* arr[]);
struct InputArray inputArrayFromDouble(const double* val);

struct Mat getMat(struct InputArray* src, int idx);
struct Mat getMat_(struct InputArray* src, int idx);
void getMatVector(struct InputArray* src, struct Mat* mv[]);

int getFlags(struct InputArray* src);
void* getObj(struct InputArray* src);
struct Size getSz(struct InputArray* src);

int dims(struct InputArray* src, int i);
int cols(struct InputArray* src, int i);
int rows(struct InputArray* src, int i);
struct Size sizeOfInputArray(struct InputArray* src, int i);
int sizend(struct InputArray* src, int* sz, int i);

size_t inputArrayTotal(struct InputArray* src, int i);
int inputArrayType(struct InputArray* src, int i);
int inputArrayDepth(struct InputArray* src, int i);
int inputArrayChannels(struct InputArray* src, int i);
bool inputArrayIsContinuous(struct InputArray* src, int i);
bool inputArrayIsSubmatrix(struct InputArray* src, int i);
bool inputArrayIsEmpty(struct InputArray* src);

size_t offset(struct InputArray* src, int i);
size_t step(struct InputArray* src, int i);
bool isMat(struct InputArray* src);

bool isMatVector(struct InputArray* src);


#endif /* input_array_h */
