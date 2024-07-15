#include "camera.hpp"

namespace Camera{

cv::VideoCapture cap;

void initCamera(int camera_id)
{
    cap.open(camera_id);
    if (!cap.isOpened())
    {
        std::cerr << "Error: Could not open camera." << std::endl;
        exit(1);
    }
}

void getFrame(cv::Mat& frame){
    cap.read(frame);
}

Eigen::Vector3d gather_color(cv::Mat& frame, Object::Circle& obj){
    cv::Mat mask = cv::Mat::zeros(frame.size(), CV_8UC1);
    cv::circle(mask, cv::Point(obj.pos.x(), obj.pos.y()), obj.radius, cv::Scalar(255), -1);
    cv::Scalar color = cv::mean(frame, mask);
    return Eigen::Vector3d(color[0], color[1], color[2]);
}

Eigen::Vector3d gather_color(cv::Mat& frame, Object::Rectangle& obj){
    cv::Mat mask = cv::Mat::zeros(frame.size(), CV_8UC1);
    cv::rectangle(mask, cv::Point(obj.pos.x() - obj.width / 2, obj.pos.y() - obj.height / 2), cv::Point(obj.pos.x() + obj.width / 2, obj.pos.y() + obj.height / 2), cv::Scalar(255), -1);
    cv::Scalar color = cv::mean(frame, mask);
    return Eigen::Vector3d(color[0], color[1], color[2]);
}


} // namespace Camera