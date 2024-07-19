#include "field.hpp"

#include "display.hpp"

namespace Field{


void Field::drawField(cv::Mat& frame)
{
    for (auto& rect : rects)
    {
        Display::draw_object(frame, rect);
    }
    Display::draw_object(frame, chara);
    Display::drawGoal(frame,goal);
}

void Field::drawChara(cv::Mat& frame)
{
    Display::draw_object(frame, chara);
}


bool Field::timeUpdate(double dt_ms){
    // for (auto& rect : rects)
    // {
    //     Display::draw_object(frame, rect);
    // }
    // Display::draw_object(frame, chara);
    return Object::chara_timeUpdate(this->chara,dt_ms);
}

bool Field::isGoal(){
    return Object::collides(this->chara, this->goal);
}

void initField(int stage_id)
{
    field.chara.pos = Object::st_pos[stage_id];
    field.clear_rects();
    if (stage_id == 0){
        for (int i = 0; i < 12; i++)
        {
            Object::Rectangle rect(100, 100);
            rect.pos << i * 100 + 100, 500;
            if (i == 3 || i == 6 || i == 7 || i == 9 || i == 11){
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
        rect.pos << 8 * 100 + 100, 400;
        field.add_rect(rect);
        rect.pos << 9 * 100 + 100, 300;
        field.add_rect(rect);
        field.chara.pos << 100 , 300;
        field.goal.pos << 1000, 400;
    }else if (stage_id == 1){
        field.chara.pos << 200, 200;
        field.goal.pos << 1000, 500;
        std::vector<std::pair<int,int>> kahen_yuka ={
            {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},
                        {2,1},            //{5,1},{6,1},{7,1},
                        {2,2},{3,2},{4,2},      {6,2},{7,2},
          //{0,3},{1,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},
        };
        std::vector<std::pair<int,int>> no_tile ={
            //{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},
              {0,1},     {2,1},            {5,1},{6,1},{7,1},{8,1},
              {0,2},{1,2}/*,{2,2},{3,2},{4,2}*/     /*{6,2},{7,2}*/,{8,2},
            //{0,3},{1,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},
        };
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 4; j++){
                if (std::find(kahen_yuka.begin(),kahen_yuka.end(),std::make_pair(i,j)) != kahen_yuka.end()){
                    Object::Rectangle rect(100, 100);
                    rect.pos << i * 100 + 200, j * 100 + 300;
                    rect.type = 0;
                    field.add_rect(rect);
                }else if (std::find(no_tile.begin(),no_tile.end(),std::make_pair(i,j)) == no_tile.end()){
                    Object::Rectangle rect(100, 100);
                    rect.pos << i * 100 + 200, j * 100 + 300;
                    field.add_rect(rect);
                }
            }
        }
    }
}

} // namespace Field