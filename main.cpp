#include "objects.hpp"
#include "display.hpp"
#include "camera.hpp"
#include "field.hpp"

cv::Mat takePhoto(Display::Window& window);
void startTry(Display::Window& window,cv::Mat photo);
void stageClear(Display::Window& window,cv::Mat photo);
void moveChara(Display::Window& window, cv::Mat photo);
int stage_id = 0;


int main(int argc, char** argv){

    Camera::initCamera(0);
    Field::initField(stage_id);

    Display::Window window("Display1");
    while (true)
    {
        cv::Mat photo = takePhoto(window);
        cv::addWeighted(photo, 0.7, cv::Scalar(255, 255, 255), 0.3, 0, photo);
        startTry(window,photo);
        if (Field::field.isGoal())
        {
            stage_id ++;
            stageClear(window,photo);
            if (stage_id == 2)
            {
                break;
            }
        }
        moveChara(window,photo);
        Field::initField(stage_id);
    }
    
    return 0;
}

cv::Mat takePhoto(Display::Window& window){
    cv::Mat frame;
    while (true)
    {
        Camera::getFrame(frame);
        // frame = cv::Mat::zeros(frame.size(), CV_8UC3) + cv::Scalar(255, 255, 255);
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

void moveChara(Display::Window& window,cv::Mat photo){
    cv::Mat frame = photo.clone();
    const Eigen::Vector2d prev_pos = Field::field.chara.pos;
    Eigen::Vector2d next_pos = Object::st_pos[stage_id];
    int cnt = 0;
    while (true)
    {
        cnt ++;
        Field::field.chara.pos = prev_pos + (next_pos - prev_pos) * cnt / 30.0;
        Field::field.chara.vel = {0,0};
        frame = photo.clone();
        Field::field.drawChara(frame);
        window.show(frame);
        cv::waitKey(30);
        if (cnt == 30)
        {
            break;
        }
    }
}

void stageClear(Display::Window& window,cv::Mat photo){
    cv::Mat frame = photo.clone();
    int cnt = 0;
    while (true)
    {
        frame = photo.clone();
        cnt++;
        cnt %= 20;
        if (cnt < 10)
        {
            Field::field.goal.width += 1;
            Field::field.goal.height += 1;
        }else{
            Field::field.goal.width -= 1;
            Field::field.goal.height -= 1;
        }
        Field::field.drawField(frame);
        cv::putText(frame, "Clear!", cv::Point(100, 100), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(0, 0, 0), 2, cv::LINE_AA);
        window.show(frame);
        if (cv::waitKey(30) >= 0)
        {
            break;
        }
    }
}