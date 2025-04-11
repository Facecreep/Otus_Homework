//
// Created by Faceecreep on 06.04.2025.
//

#include "Task2001.h"
#include <iostream>

int Task2001::main(){
    int a1, b1;
    int a2, b2;
    int a3, b3;

    std::cin >> a1 >> b1;
    std::cin >> a2 >> b2;
    std::cin >> a3 >> b3;

    std::cout << a1 - a3 << " " << b1 - b2 << std::endl;

    return 0;
}