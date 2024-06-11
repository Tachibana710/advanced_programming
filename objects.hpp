
#include <iostream>
#include <eigen3/Eigen/Core>

class object_base
{
    public:
        object_base() : 
            pos(Eigen::Vector2d::Zero()),
            color(Eigen::Vector3d::Zero()) {};
        Eigen::Vector2d pos;
        Eigen::Vector3d color;
        void change_color(Eigen::Vector3d new_color)
        {
            color = new_color;
        }
    private:
};

class Circle : public object_base
{
    public:
        Circle(double r) : object_base(), radius(r) {};
        double radius;
    private:
};

class Rectangle : public object_base
{
    public:
        Rectangle(double w, double h) : object_base(), width(w), height(h) {};
        double width;
        double height;
    private:
};

template <typename T1, typename T2>
bool collides(T1& obj1, T2& obj2);