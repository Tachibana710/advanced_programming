#include "objects.hpp"
#include "display.hpp"
#include "camera.hpp"

int main(int argc, char** argv){
    Object::Circle circle(50);
    circle.pos << 100, 100;
    circle.color << 255, 0, 0;

    Object::Rectangle rectangle(100, 100);
    rectangle.pos << 200, 200;
    rectangle.color << 0, 255, 0;

    Camera::initCamera(0);

    Display::Window window("Display1");
    while (true)
    {
        cv::Mat frame;
        Camera::getFrame(frame);
        circle.change_color(Camera::gather_color(frame, circle));
        Display::add_object(frame, circle);
        rectangle.change_color(Camera::gather_color(frame, rectangle));
        Display::add_object(frame, rectangle);
        window.show(frame);
        if (cv::waitKey(30) >= 0)
        {
            break;
        }
    }
    
    return 0;
}