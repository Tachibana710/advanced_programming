#pragma once

#include "opencv4/opencv2/opencv.hpp"
#include "objects.hpp"

namespace Display{

class Window
{
public:
    Window(const std::string& title = "Windows")
    {
        static int count = 0;
        count++;
        std::string new_title = title + "_" + std::to_string(count);
        cv::namedWindow(new_title, cv::WINDOW_AUTOSIZE);
        this->title = new_title;
    }

    ~Window()
    {
        cv::destroyWindow(title);
    }

    void show(const cv::Mat& image)
    {
        cv::imshow(title, image);
    }

    std::string title;
};

void draw_object(cv::Mat& image, Object::Circle& obj);
void draw_object(cv::Mat& image, Object::Rectangle& obj);


} // namespace Display

