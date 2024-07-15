#pragma once

#include "objects.hpp"

#include <iostream>

#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

#include <eigen3/Eigen/Core>

namespace Camera{


void initCamera(int camera_id);

void getFrame(cv::Mat& frame);

Eigen::Vector3d gather_color(cv::Mat& frame, Object::Circle& obj);
Eigen::Vector3d gather_color(cv::Mat& frame, Object::Rectangle& obj);

} // namespace Camera