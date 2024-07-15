#pragma once

#include <iostream>

#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

namespace Camera{


void initCamera(int camera_id);

cv::Mat getFrame(cv::Mat& frame);


} // namespace Camera