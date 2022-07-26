//
//  capi.h
//  javacv
//
//  Created by Denis Makogon on 19.07.2022.
//

#ifndef capi_h
#define capi_h

#ifdef __cplusplus
extern "C" {
#endif

// original content
#include "opencv2/core/hal/interface.h"

// C ports
#include "include/mat.hpp"
#include "include/size.hpp"
#include "include/range.hpp"
#include "include/point.hpp"
#include "include/rect.hpp"
#include "include/input_array.hpp"
#include "include/output_array.hpp"

#ifdef __cplusplus
}
#endif

#endif /* capi_h */
