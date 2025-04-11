//
// Created by Faceecreep on 06.04.2025.
//

#include "Task1001.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int Task1001::main(){
    int value;

    std::vector<int> vector;

    while (std::cin >> value)
        vector.push_back(value);

    std::reverse(vector.begin(), vector.end());

    for(int element: vector)
        std::cout << std::sqrt(element) << std::endl;

    return 0;
}