//
// Created by Faceecreep on 05.04.2025.
//

#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape {
public:
    using Shape::Shape;



    void draw() override;
    void erase() override;
};


#endif //UNTITLED_RECTANGLE_H
