//
//  mat.h
//  javacv
//
//  Created by Denis Makogon on 19.07.2022.
//

#ifndef mat_h
#define mat_h

#include "include/mat_type.h"

#ifdef __cplusplus
extern "C" {
#endif

void mat(struct Mat* cv_m);
void matAsCopy(struct Mat* src, struct Mat* dest);
void matFromColsRowsType(struct Mat* cv_m, int rows, int cols, int type);
void matAsNdimentionType(struct Mat* cv_m, int ndims, const int *sizes, int type);
void matFromColsRowsTypeAndData(struct Mat* cv_m, int rows, int cols, int type, void* data);
void matAsNdimentionTypeAndData(struct Mat* cv_m, int ndims, const int *sizes, int type, void* data);

#ifdef __cplusplus
}
#endif

#endif /* mat_h */
