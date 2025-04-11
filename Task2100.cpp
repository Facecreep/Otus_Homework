//
// Created by Faceecreep on 11.04.2025.
//

#include "Task2100.h"
#include <iostream>


int Task2100::main() {
    int n;

    std::cin >> n;

    int total = 200;

    for (int i = 0; i < n; ++i) {
        std::string string;
        std::cin >> string;

        total += (string.find("+one") != std::string::npos) ? 200 : 100;
    }

    std::cout << ((total == 1300) ? 1400 : total) << std::endl;

    return 0;
}
