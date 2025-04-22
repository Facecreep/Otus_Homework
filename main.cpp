#include <iostream>
#include <vector>
#include <memory>

#include "Shapes/Shapes.h"
#include "Canvas.h"
#include "FileHandler.h"

enum Click_state{
    create,
    erase
};

//Создание и удаление примитива
void click_on_canvas(Canvas canvas, Click_state state, Canvas::Shape_type selected_shape_type, int x, int y){
    switch (state) {
        case create:
            canvas.add_shape(selected_shape_type, 0, 0, 0, 0);

            break;
        case erase:
            canvas.remove_shape_at(x, y);

            break;
    }
}

//Сохранение документа
void save_canvas_to_file(Canvas canvas){
    FileHandler::write_to_file(canvas.get_canvas_data());
}

//Загрузка документа
Canvas load_canvas_from_file(){
    Canvas canvas;
    for(std::vector<std::string> shape_data: FileHandler::load_from_file()){
        Canvas::Shape_type shape_type;

        if (shape_data[0] == "9Rectangle")
            shape_type = Canvas::rectangle;
        else if (shape_data[0] == "6Circle")
            shape_type = Canvas::circle;
        else if (shape_data[0] == "4Line")
            shape_type = Canvas::line;
        else
            throw std::invalid_argument("Recieved wrong shape type");

        canvas.add_shape(shape_type,
                         std::stoi(shape_data[1]),
                         std::stoi(shape_data[2]),
                         std::stoi(shape_data[3]),
                         std::stoi(shape_data[4])
        );
    }

    return canvas;
}

// Создание документа
Canvas create_canvas(){
    return Canvas();
}

int main()
{
    // Работа с GUI по типу выбора примитива, обработки кнопок, вызывающих функции выше и т.д.

    return 0;
}
