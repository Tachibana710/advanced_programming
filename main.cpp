#include "objects.hpp"
#include "display.hpp"
#include "camera.hpp"
#include "field.hpp"

cv::Mat takePhoto(Display::Window& window);

int main(int argc, char** argv){

    Camera::initCamera(0);
    Field::initField(0);

    Display::Window window("Display1");
    cv::Mat photo = takePhoto(window);
    
    return 0;
}

cv::Mat takePhoto(Display::Window& window){
    Object::Circle circle(50);
    circle.pos << 100, 100;
    circle.color << 255, 0, 0;

    Object::Rectangle rectangle(100, 100);
    rectangle.pos << 200, 200;
    rectangle.color << 0, 255, 0;
    cv::Mat frame;
    while (true)
    {
        Camera::getFrame(frame);
        Field::field.drawField(frame);
        window.show(frame);
        if (cv::waitKey(30) >= 0)
        {
            break;
        }
    }
    Camera::getFrame(frame);
    return frame;
}