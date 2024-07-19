#include "objects.hpp"
#include "field.hpp"

#include <eigen3/Eigen/Core>

#include <utility>
#include <vector>
#include <iostream>
#include <functional>

namespace Object{

bool collides(Circle& obj1, Circle& obj2)
{
    double distance = (obj1.pos - obj2.pos).norm();
    return distance < obj1.radius + obj2.radius;
}

bool collides(Circle& obj1, Rectangle& obj2)
{
    double dx = std::abs(obj1.pos.x() - obj2.pos.x());
    double dy = std::abs(obj1.pos.y() - obj2.pos.y());
    double dist_x = dx - obj2.width / 2;
    double dist_y = dy - obj2.height / 2;
    // return std::make_pair<bool,bool>(dist_x <= obj1.radius, dist_y <= obj1.radius);
    if (dist_x > obj1.radius  -5|| dist_y > obj1.radius - 5)
    {
        return false;
    }
    if (dist_x <= 0 || dist_y <= 0)
    {
        return true;
    }
    return dist_x * dist_x + dist_y * dist_y <= (obj1.radius - 5) * (obj1.radius - 5);
}

bool collides(Rectangle& obj1, Circle& obj2)
{
    return collides(obj2, obj1);
}
bool collides(Rectangle& obj1, Rectangle& obj2)
{
    double dx = std::abs(obj1.pos.x() - obj2.pos.x());
    double dy = std::abs(obj1.pos.y() - obj2.pos.y());
    double dist_x = dx - (obj1.width + obj2.width) / 2;
    double dist_y = dy - (obj1.height + obj2.height) / 2;
    return dist_x <= 0 && dist_y <= 0;
}

void decideType(Rectangle& obj){
    if (obj.type != 0){
        return;
    }
    double diff_norm = 1e9;
    double tmp_type = 1;
    for (auto type : type_list){
        double diff = (obj.color - type.second).norm();
        std::cout << "type:" << type.first << " diff:" << diff << std::endl;
        if (diff < diff_norm){
            tmp_type = type.first;
            diff_norm = diff;
        }
    }
    obj.type = tmp_type;
    obj.change_color(type_list[tmp_type].second);
}

bool chara_timeUpdate(Circle& chara, double dt){ //戻り地: 詰み⇢true それ以外⇢false
    // auto& rects = Field::field.rects;
    std::function<bool(Eigen::Vector2d)> will_colide = [&](Eigen::Vector2d next_vel){
        auto& rects = Field::field.rects;
        Circle next_chara = chara;
        next_chara.pos += dt/1000.0 * next_vel;
        for (auto& r : rects){
            if (collides(r, next_chara) && r.type != 2){
                return true;
            }
        }
        return false;
    };

    Eigen::Vector2d next_pos = chara.pos;
    Eigen::Vector2d next_vel{200, chara.vel.y() + 30};
    if (will_colide({next_vel.x(), 0})){
        next_vel.x() = 0;
    }
    if (will_colide({0, next_vel.y()})){
        next_vel.y() = 0;
    }
    next_pos += dt/1000.0 * next_vel;

    static int stop_count = 0;
    if ((chara.pos - next_pos).norm() < 1e-3){
        stop_count++;
    }
    if (stop_count > 100){
        return true;
    }

    if (chara.pos.y() > 800){
        return true;
    }
    
    chara.pos = next_pos;
    chara.vel = next_vel;
    return false;
}

} // namespace Object