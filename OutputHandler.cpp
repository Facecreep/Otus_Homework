//
// Created by Faceecreep on 17.04.2025.
//

#include "OutputHandler.h"

void OutputHandler::output_to_file(const std::string &file_name, std::vector<std::string> output_vector) {
    std::fstream fstream{file_name, fstream.binary | fstream.trunc | fstream.out};

    if (!fstream.is_open())
        std::cout << "failed to open " << file_name << '\n';
    else
    {
        std::string c_output = "bulk: ";
        for(const std::string& string: output_vector){
            fstream.write(string.c_str(), sizeof(string.c_str()));

            c_output += string + ", ";
        }

        c_output.pop_back();
        c_output.pop_back();
        std::cout << c_output << std::endl;
    }
}
