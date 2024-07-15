#include "opencv4/opencv2/opencv.hpp"
#include "objects.hpp"
#include "display.hpp"
#include <coroutine>

using namespace Display;

namespace Display{

void add_object(cv::Mat& image, Object::Circle& obj)
{
    cv::circle(image, cv::Point(obj.pos.x(), obj.pos.y()), obj.radius, cv::Scalar(obj.color.x(), obj.color.y(), obj.color.z()), -1);
}

void add_object(cv::Mat& image, Object::Rectangle& obj)
{
    cv::rectangle(image, cv::Point(obj.pos.x() - obj.width / 2, obj.pos.y() - obj.height / 2), cv::Point(obj.pos.x() + obj.width / 2, obj.pos.y() + obj.height / 2), cv::Scalar(obj.color.x(), obj.color.y(), obj.color.z()), -1);
}

} // namespace Display