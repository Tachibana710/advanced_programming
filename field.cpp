#include "field.hpp"

#include "display.hpp"

namespace Field{

void Field::drawField(cv::Mat& frame)
{
    for (auto& rect : rects)
    {
        Display::draw_object(frame, rect);
    }
}

void initField(int stage_id)
{
    if (stage_id == 0){
        for (int i = 0; i < 12; i++)
        {
            Object::Rectangle rect(100, 100);
            rect.pos << i * 100 + 100, 500;
            if (i == 3 || i == 6 || i == 7 || i == 9){
                rect.type = 0;
            }
            field.add_rect(rect);
        }
        Object::Rectangle rect(100, 100);
        rect.pos << 4 * 100 + 100, 400;
        rect.type = 0;
        field.add_rect(rect);
        rect.pos << 7 * 100 + 100, 400;
        rect.type = 0;
        field.add_rect(rect);
    }else if (stage_id == 1){
        Object::Rectangle rect5(100, 100);
        rect5.pos << 100, 100;
        rect5.color << 200, 200, 200;
        field.add_rect(rect5);

        Object::Rectangle rect6(100, 100);
        rect6.pos << 200, 200;
        rect6.color << 200, 200, 200;
        field.add_rect(rect6);
    }
}

} // namespace Field