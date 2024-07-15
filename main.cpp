#include "objects.hpp"
#include "display.hpp"
#include "camera.hpp"

int main(int argc, char** argv){
    Object::Circle circle(50);
    circle.pos << 100, 100;
    circle.color << 255, 0, 0;

    Display::Window window("Display1");
    while (true)
    {
        cv::Mat frame;
        frame = Camera::getFrame();
        Display::add_object(frame, circle);
        window.show(frame);
        if (cv::waitKey(30) >= 0)
        {
            break;
        }
    }
    
    return 0;
}