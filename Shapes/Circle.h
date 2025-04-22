//
// Created by Faceecreep on 05.04.2025.
//

#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H

#include "Shape.h"

class Circle: public Shape {
public:
    void draw() override;
    void erase() override;
    bool is_coordinate_inside(int coord_x, int coord_y) override;

    using Shape::Shape;
};


#endif //UNTITLED_CIRCLE_H
