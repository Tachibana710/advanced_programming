#pragma once

#include "objects.hpp"

#include <vector>

#include <opencv4/opencv2/core/core.hpp>


namespace Field{

    class Field
    {
        public:
            Field(){
                chara.change_color({200,200,0});
                // chara.radius = 25;
                goal.change_color({0,200,200});
            };
            void drawField(cv::Mat& frame);
            void drawChara(cv::Mat& frame);
            void add_rect(Object::Rectangle& rect){
                rects.push_back(rect);
            }
            void clear_rects(){
                rects.clear();
            }
            bool isGoal();
            bool timeUpdate(double dt_ms);
            std::vector<Object::Rectangle> rects;
            Object::Circle chara = Object::Circle(30);
            Object::Rectangle goal = Object::Rectangle(30, 30);
    };

    inline Field field;

    void initField(int stage_id);



} // namespace Field