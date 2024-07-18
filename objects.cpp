#include "objects.hpp"

#include <eigen3/Eigen/Core>

#include <utility>
#include <vector>

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
    if (dist_x > obj1.radius || dist_y > obj1.radius)
    {
        return false;
    }
    if (dist_x <= 0 || dist_y <= 0)
    {
        return true;
    }
    return dist_x * dist_x + dist_y * dist_y <= obj1.radius * obj1.radius;
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
    const std::vector<std::pair<int, Eigen::Vector3d>> type_list = {
        {0, Eigen::Vector3d(0, 0, 0)}, // 可変床
        {1, Eigen::Vector3d(10, 10, 10)}, // 床
        {2, Eigen::Vector3d(255, 255, 255)}, // 白
        {3, Eigen::Vector3d(0, 0, 255)},
        {4, Eigen::Vector3d(255, 255, 0)},
        {5, Eigen::Vector3d(0, 255, 255)},
        {6, Eigen::Vector3d(255, 0, 255)},
        {7, Eigen::Vector3d(255, 0, 0)},
        {8, Eigen::Vector3d(0, 255, 0)},

    };
    double diff_norm = 1e9;
    double tmp_type = 1;
    for (auto type : type_list){
        double diff = (obj.color - type.second).norm();
        if (diff < diff_norm){
            tmp_type = type.first;
            diff_norm = diff;
        }
    }
    obj.type = tmp_type;
    obj.change_color(type_list[tmp_type].second);
}

} // namespace Object