//
// Created by Faceecreep on 06.04.2025.
//

#include "Task1197.h"
#include <iostream>

int Task1197::main() {
    char char_position[2];

    char alphabet[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    int total_cycles;
    std::cin >> total_cycles;

    for(int cycle = 0; cycle < total_cycles; cycle++){
        std::cin >> char_position;

        int int_position[2];

        for (int i = 0; i <=8; i++) {
            if (alphabet[i] == char_position[0]) {
                int_position[0] = i + 1;
                break;
            }
        }

        int_position[1] = (int)(char_position[1]) - 48;

        int x_pos = int_position[0];
        int y_pos = int_position[1];

        int move_options = 8;

        if(3 < x_pos and x_pos < 6 and
           3 < y_pos and y_pos < 6){
        }
        else{
            int a = 1;

            if(x_pos - 2 <= 0 or y_pos - 1 <= 0)
                move_options--;
            if(x_pos - 2 <= 0 or y_pos + 1 >= 9)
                move_options--;

            if(x_pos + 2 >= 9 or y_pos - 1 <= 0)
                move_options--;
            if(x_pos + 2 >= 9 or y_pos + 1 >= 9)
                move_options--;

            if(x_pos - 1 <= 0 or y_pos - 2 <= 0)
                move_options--;
            if(x_pos + 1 >= 9 or y_pos - 2 <= 0)
                move_options--;

            if(x_pos - 1 <= 0 or y_pos + 2 >= 9)
                move_options--;
            if(x_pos + 1 >= 9 or y_pos + 2 >= 9)
                move_options--;
        }

        std::cout << move_options << std::endl;
    }

    return 0;
}