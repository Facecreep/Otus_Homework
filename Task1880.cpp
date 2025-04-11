//
// Created by Faceecreep on 11.04.2025.
//

#include "Task1880.h"
#include <iostream>
#include <vector>
#include <algorithm>

int Task1880::main() {
    std::vector<int> unique_numbers, repeated_numbers;

    for (int i = 0; i < 3; ++i) {
        int number_count;
        std::cin >> number_count;

        for (int j = 0; j < number_count; ++j) {
            int number;
            std::cin >> number;

            if (std::find(repeated_numbers.begin(), repeated_numbers.end(), number) != repeated_numbers.end())
                continue;

            const auto found_number = std::find(unique_numbers.begin(), unique_numbers.end(), number);
            if(found_number != unique_numbers.end()){
                unique_numbers.erase(found_number);

                repeated_numbers.push_back(number);
            }  else
                unique_numbers.push_back(number);
        }
    }

    std::cout << unique_numbers.size() << std::endl;
}