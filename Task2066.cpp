//
// Created by Faceecreep on 11.04.2025.
//

#include "Task2066.h"
#include <iostream>
#include <algorithm>
#include <array>

int Task2066::main() {
    std::array<int, 3> array;

    std::cin >> array[0] >> array[1] >> array[2];

    std::sort(array.begin(), array.end());

    std::cout << array[0] - ((array[1] == 1 || array[1] == 0) ? array[1] + array[2] : array[1] * array[2]) << std::endl;

    return 0;
}
