//
//  _export.hpp
//  javacv
//
//  Created by Denis Makogon on 18.07.2022.
//

#ifndef _export_hpp
#define _export_hpp

#include <string>

#include "include/mat_type.h"
#include "include/input_array_type.h"
#include "include/output_array_type.h"

#include "opencv2/core/mat.hpp"

void CV_MatToMat(cv::Mat& image, Mat& exMat);
void matToCV_Mat(Mat& exMat, cv::Mat& mat);

void CV_OutputArrayToOutputArray(cv::OutputArray& src, OutputArray* dst);
void CV_InputArrayToInputArray(cv::InputArray& src, struct InputArray* dst);

#endif /* _export_hpp */
