//
// Created by Faceecreep on 05.04.2025.
//

#include "Line.h"
#include <iostream>

void Line::draw() {
    std::cout << "Drawn Line" << std::endl;
}

void Line::erase() {
    std::cout << "Erased Line" << std::endl;
}

bool Line::is_coordinate_inside(int coord_x, int coord_y) {
    return Shape::is_coordinate_inside(coord_x, coord_y);
}
