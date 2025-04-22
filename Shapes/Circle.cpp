//
// Created by Faceecreep on 05.04.2025.
//

#include "Circle.h"
#include <iostream>

void Circle::draw() {
    std::cout << "Drawn Circle" << std::endl;
}

void Circle::erase() {
    std::cout << "Erased Circle" << std::endl;
}

bool Circle::is_coordinate_inside(int coord_x, int coord_y) {
    return Shape::is_coordinate_inside(coord_x, coord_y);
}
