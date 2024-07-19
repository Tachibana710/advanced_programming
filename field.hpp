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
            };
            void drawField(cv::Mat& frame);
            void add_rect(Object::Rectangle& rect){
                rects.push_back(rect);
            }
            void clear_rects(){
                rects.clear();
            }
            bool timeUpdate(double dt_ms);
            std::vector<Object::Rectangle> rects;
            Object::Circle chara = Object::Circle(30);
    };

    inline Field field;

    void initField(int stage_id);

} // namespace Field