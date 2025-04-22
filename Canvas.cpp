//
// Created by Faceecreep on 05.04.2025.
//

#include <memory>
#include <algorithm>

#include "Canvas.h"

Canvas::Canvas(){

}
Canvas::~Canvas(){

}

void Canvas::add_shape(Shape_type shape_type, int x, int y, int width, int height) {
    Shape *shape;

    switch (shape_type) {

        case circle:
            shape = new Circle(x, y, width, height);
            break;
        case rectangle:
            shape = new Rectangle(x, y, width, height);
            break;
        case line:
            shape = new Line(x, y, width, height);
            break;

    }

    shape->draw();

    shapes.push_back(shape);
}

void Canvas::remove_shape(Shape *shape) {
    if (!shape) return;

    shape->erase();

    shapes.erase(std::find(shapes.begin(), shapes.end(), shape));
}

void Canvas::remove_shape_at(int x, int y) {
    Shape* shape = select_shape_at(x, y);

    if (!shape){
        remove_shape(shape);
    }
}

Shape* Canvas::select_shape_at(int x, int y) {
    for(Shape *shape: shapes)
        if (shape->is_coordinate_inside(x, y))
            return shape;

    return nullptr;
}

std::vector<std::vector<std::string>> Canvas::get_canvas_data() {
    std::vector<std::vector<std::string>> result;

    for(Shape* shape: shapes){
        result.push_back(shape->serialize());
    }

    return result;
}
