//
// Created by Faceecreep on 11.04.2025.
//

#include "Task1820.h"
#include <iostream>

int Task1820::main() {
    int n, k;

    std::cin >> n >> k;

    std::cout << n * 2 / k + ((n * 2 / k == 0) ? 0 : 1) << std::endl;

    return 0;
}