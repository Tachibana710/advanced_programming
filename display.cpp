#include "opencv4/opencv2/opencv.hpp"
#include "objects.hpp"
#include "display.hpp"
#include "camera.hpp"
#include <coroutine>

using namespace Display;

namespace Display{

void draw_object(cv::Mat& image, Object::Circle& obj)
{
    if (obj.type == 0){
        obj.change_color(Camera::gather_color(image, obj));
    }
    //edge
    cv::circle(image, cv::Point(obj.pos.x(), obj.pos.y()), obj.radius, cv::Scalar(200, 200, 200), 1);
    cv::circle(image, cv::Point(obj.pos.x(), obj.pos.y()), obj.radius - 5, cv::Scalar(obj.color.x(), obj.color.y(), obj.color.z()), -1);
}

void draw_object(cv::Mat& image, Object::Rectangle& obj)
{
    if (obj.type == 0){
        obj.change_color(Camera::gather_color(image, obj));
    }
    //edge
    cv::rectangle(image, cv::Point(obj.pos.x() - obj.width / 2 + 4, obj.pos.y() - obj.height / 2 + 4)
        ,cv::Point(obj.pos.x() + obj.width / 2 - 4, obj.pos.y() + obj.height / 2 - 4), cv::Scalar(200, 200, 200), 2);
    if (obj.type ==2){
        return;
    }
    cv::rectangle(image, cv::Point(obj.pos.x() - obj.width / 2 + 9, obj.pos.y() - obj.height / 2 + 9)
        ,cv::Point(obj.pos.x() + obj.width / 2 - 9, obj.pos.y() + obj.height / 2 - 9), cv::Scalar(obj.color.x(), obj.color.y(), obj.color.z()), -1);
}

void drawGoal(cv::Mat& frame, Object::Rectangle& goal)
{
    cv::rectangle(frame, cv::Point(goal.pos.x() - goal.width / 2, goal.pos.y() - goal.height / 2)
        ,cv::Point(goal.pos.x() + goal.width / 2, goal.pos.y() + goal.height / 2), cv::Scalar(0, 0, 255), 2);
    cv::rectangle(frame, cv::Point(goal.pos.x() - goal.width / 2 + 5, goal.pos.y() - goal.height / 2 + 5)
        ,cv::Point(goal.pos.x() + goal.width / 2 - 5, goal.pos.y() + goal.height / 2 - 5), cv::Scalar(0, 0, 255), -1);
}

} // namespace Display