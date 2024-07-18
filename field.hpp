#pragma once

#include "objects.hpp"

#include <vector>

#include <opencv4/opencv2/core/core.hpp>


namespace Field{

    class Field
    {
        public:
            Field(){};
            void drawField(cv::Mat& frame);
            void add_rect(Object::Rectangle& rect){
                rects.push_back(rect);
            }
            void clear_rects(){
                rects.clear();
            }
        private:
            std::vector<Object::Rectangle> rects;
    };

    inline Field field;

    void initField(int stage_id);

} // namespace Field