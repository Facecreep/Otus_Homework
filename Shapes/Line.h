//
// Created by Faceecreep on 05.04.2025.
//

#ifndef UNTITLED_LINE_H
#define UNTITLED_LINE_H

#include "Shape.h"

class Line: public Shape {
public:
    void draw() override;
    void erase() override;

    bool is_coordinate_inside(int coord_x, int coord_y) override;

    using Shape::Shape;
};


#endif //UNTITLED_LINE_H
