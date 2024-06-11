#include "objects.hpp"

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