//
// Created by Faceecreep on 05.04.2025.
//

#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include <vector>
#include <memory>
#include <string>

#include "Shapes/Shapes.h"

class Canvas {
public:
    enum Shape_type{
        circle,
        rectangle,
        line
    };

    Canvas();
    ~Canvas();

    void add_shape(Shape_type shape_type, int x, int y, int width, int height);
    void remove_shape(Shape *shape);

    Shape * select_shape_at(int x, int y);
    void remove_shape_at(int x, int y);

    std::vector<std::vector<std::string>> get_canvas_data();

private:
    std::vector<Shape*> shapes;
};


#endif //UNTITLED_CANVAS_H
