#pragma once

#include <iostream>
#include <eigen3/Eigen/Core>

namespace Object{

    class object_base
    {
        public:
            object_base() : 
                pos(Eigen::Vector2d::Zero()),
                color(Eigen::Vector3d::Zero()) {};
            Eigen::Vector2d pos;
            Eigen::Vector3d color = Eigen::Vector3d(150, 150, 150);
            void change_color(Eigen::Vector3d new_color)
            {
                color = new_color;
            }
            int type = 1;
            // 0: 可変床
            // 1: 床
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

    bool collides(Circle& obj1, Circle& obj2);
    bool collides(Circle& obj1, Rectangle& obj2);
    bool collides(Rectangle& obj1, Circle& obj2);
    bool collides(Rectangle& obj1, Rectangle& obj2);
}
