//
// Created by Faceecreep on 06.04.2025.
//

#include "Task1787.h"
#include <iostream>

int Task1787::main() {
    int car_rate, minutes;

    std::cin >> car_rate >> minutes;

    int value, sum;
    for (int i = 0; i < minutes; ++i) {
        std::cin >> value;

        sum += value - car_rate;
        sum = (sum < 0) ? 0 : sum;
    }

    std::cout << sum;
}