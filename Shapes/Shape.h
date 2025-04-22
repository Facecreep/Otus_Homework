//
// Created by Faceecreep on 05.04.2025.
//

#include <vector>
#include <string>

#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H


class Shape {
public:
    Shape(int x, int y, int width, int height);

    virtual void draw();
    virtual void erase();
    virtual bool is_coordinate_inside(int coord_x, int coord_y);

    std::vector<std::string> serialize();

private:
    int x, y;
    int width, height;
};


#endif //UNTITLED_SHAPE_H
