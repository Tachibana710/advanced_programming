#include "objects.hpp"
#include "display.hpp"
#include "camera.hpp"
#include "field.hpp"

cv::Mat takePhoto(Display::Window& window);
void startTry(Display::Window& window,cv::Mat photo);

int main(int argc, char** argv){

    Camera::initCamera(0);
    Field::initField(0);

    Display::Window window("Display1");
    cv::Mat photo = takePhoto(window);
    startTry(window,photo);
    
    return 0;
}

cv::Mat takePhoto(Display::Window& window){
    cv::Mat frame;
    while (true)
    {
        Camera::getFrame(frame);
        Field::field.drawField(frame);
        window.show(frame);
        if (cv::waitKey(30) >= 0)
        {
            for (auto& r : Field::field.rects)
            {
                Object::decideType(r);
            }
            break;
        }
    }
    Camera::getFrame(frame);
    return frame;
}

void startTry(Display::Window& window,cv::Mat photo){
    //可変床を確定
    for (auto& r : Field::field.rects)
    {
        Object::decideType(r);
    }
    //背景を白黒に
    // cv::cvtColor(photo, photo, cv::COLOR_BGR2GRAY);
    cv::Mat temp = photo.clone();
    // for (int i = 0; i < 100; i++)
    // {
    //     cv::medianBlur(photo, photo, 3);
    // }
    cv::addWeighted(temp, 0.7, cv::Scalar(255, 255, 255), 0.3, 0, photo);
    cv::Mat frame = photo.clone();
    while (true)
    {
        frame = photo.clone();
        // Camera::getFrame(frame);
        bool end_flg = Field::field.timeUpdate(30);
        if (end_flg)
        {
            break;
        }
        // Object::chara_timeUpdate(Field::field.chara,30);
        Field::field.drawField(frame);
        window.show(frame);
        if (cv::waitKey(30) >= 0)
        {
            break;
        }
    }

}