//
// Created by Faceecreep on 06.04.2025.
//

#include "Task1409.h"
#include <iostream>

int Task1409::main() {
    int n, m;

    std::cin >> n >> m;

    int total = (n + m) - 1;

    std::cout << total - n << " " << total - m << std::endl;

    return 0;
}