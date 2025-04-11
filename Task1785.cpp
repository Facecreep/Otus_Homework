//
// Created by Faceecreep on 07.04.2025.
//

#include "Task1785.h"
#include <iostream>

int Task1785::main() {
    int n;

    std::cin >> n;

    if(n <= 4)
        std::cout << "few" << std::endl;
    else if(n <= 9)
        std::cout << "several" << std::endl;
    else if(n <= 19)
        std::cout << "pack" << std::endl;
    else if(n <= 49)
        std::cout << "lots" << std::endl;
    else if(n <= 99)
        std::cout << "horde" << std::endl;
    else if(n <= 249)
        std::cout << "throng" << std::endl;
    else if(n <= 499)
        std::cout << "swarm" << std::endl;
    else if(n <= 999)
        std::cout << "zounds" << std::endl;
    else
        std::cout << "legion" << std::endl;

    return 0;
}