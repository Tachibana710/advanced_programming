#pragma once

#include <iostream>
#include <eigen3/Eigen/Core>
#include <string>

namespace Object{

    inline std::vector<Eigen::Vector2d> st_pos = {
        {100,300},
        {200,200},
    };

    class object_base
    {
        public:
            object_base(){
                pos = Eigen::Vector2d(0, 0);
                vel = Eigen::Vector2d(0, 0);
            };
            Eigen::Vector2d pos;
            Eigen::Vector2d vel;
            Eigen::Vector3d color = Eigen::Vector3d(10, 10, 10);
            void change_color(Eigen::Vector3d new_color)
            {
                color = new_color;
            }
            int type = 1;
        private:
    };

    const std::vector<std::pair<int, Eigen::Vector3d>> type_list = {
        {0, Eigen::Vector3d(0, 0, 0)}, // 可変床
        {1, Eigen::Vector3d(10, 10, 10)}, // 床
        {2, Eigen::Vector3d(255, 255, 255)}, // 白
        {3, Eigen::Vector3d(0, 255, 255)},
        {4, Eigen::Vector3d(255, 0, 0)},
        // {5, Eigen::Vector3d(50, 200, 200)},
        // {6, Eigen::Vector3d(200, 50, 200)},
        // {7, Eigen::Vector3d(255, 0, 0)},
        // {8, Eigen::Vector3d(0, 255, 0)},
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

    bool chara_timeUpdate(Circle& chara, double dt);

    bool collides(Circle& obj1, Circle& obj2);
    bool collides(Circle& obj1, Rectangle& obj2);
    bool collides(Rectangle& obj1, Circle& obj2);
    bool collides(Rectangle& obj1, Rectangle& obj2);

    void decideType(Rectangle& obj);
}
