#include "objects.hpp"
#include "display.hpp"

int main(int argc, char** argv){
    Object::Circle circle(50);
    circle.pos << 100, 100;
    circle.color << 255, 0, 0;

    cv::Mat original;
    cv::VideoCapture capture(0);

    if (!capture.isOpened())
    {
        std::cerr << "Error opening camera" << std::endl;
        return -1;
    }

    Display::Window window("Display1");
    while (true)
    {
        cv::Mat frame;
        capture.read(frame);
        Display::add_object(frame, circle);
        window.show(frame);
        if (cv::waitKey(30) >= 0)
        {
            break;
        }
    }
    
    return 0;
}