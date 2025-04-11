//
// Created by Faceecreep on 06.04.2025.
//

#include "Task1877.h"
#include <iostream>

int Task1877::main() {
    int first_code, second_code;

    std::cin >> first_code;
    std::cin >> second_code;

    if(first_code % 2 == 0 or second_code % 2 != 0)
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;

    return 0;
}