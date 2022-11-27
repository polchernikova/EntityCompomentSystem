#pragma once

#include <vector>


class Vector {
public:
    Vector(int x, int y) : x_(x), y_(y) {}

    friend Vector operator*(const Vector &c1, int c) {
        return {c1.x_ * c, c1.y_ * c};
    }

    friend Vector operator+(const Vector& v1, const Vector& v2) {
        return {v1.x_ + v2.x_, v2.y_ + v2.y_};
    }

private:
    int x_;
    int y_;
};

struct TransformationComponent {
    Vector position = {0, 0};
};


struct MotionComponent {
    int initial_speed = 1;
    Vector direction = {1, 1};
    int current_speed = initial_speed;
};


