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

cv::Mat getFrame(cv::Mat& frame){
    cv::Mat frame;
    cap >> frame;
    return frame;
}

} // namespace Camera