//
// Created by Faceecreep on 17.04.2025.
//

#ifndef HELLOWORLD_OUTPUTHANDLER_H
#define HELLOWORLD_OUTPUTHANDLER_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <future>
#include <thread>
#include <mutex>

class OutputHandler {
public:
    static void output_list(const std::string &file_name, const std::vector<std::string>& output_vector);
    static void output_to_console(const std::vector<std::string>& output_vector);
    static void output_to_file(const std::string &file_name, const std::vector<std::string>& output_vector);

private:
    static bool is_output_to_first_file;
};


#endif //HELLOWORLD_OUTPUTHANDLER_H
