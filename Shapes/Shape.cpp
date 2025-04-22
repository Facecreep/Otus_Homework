//
// Created by Faceecreep on 05.04.2025.
//

#include "Shape.h"
#include <iostream>
#include <vector>

Shape::Shape(int x, int y, int width, int height)
:x(x),
 y(y),
 width(width),
 height(height){}

void Shape::draw() {
    std::cout << "drawn shape" << std::endl;
}

void Shape::erase() {
    std::cout << "Erased Shape" << std::endl;
}

std::vector<std::string> Shape::serialize() {

    std::vector<std::string> serialized_fields{typeid(*this).name(),
                                               std::to_string(x),
                                               std::to_string(y),
                                               std::to_string(width),
                                               std::to_string(height)};

    std::cout << "Serialized " << serialized_fields[0] << " with values: " << std::endl <<
    "x: " << serialized_fields[1] << std::endl <<
    "y: " << serialized_fields[2] << std::endl <<
    "width: " << serialized_fields[3] << std::endl <<
    "height: " << serialized_fields[4] << std::endl;

    return serialized_fields;
}

bool Shape::is_coordinate_inside(int coord_x, int coord_y) {
    // Проверка на то, находится ли координата внутри 
    
    return false;
}



