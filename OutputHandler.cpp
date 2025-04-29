//
// Created by Faceecreep on 17.04.2025.
//

#include "OutputHandler.h"

void OutputHandler::output_list(const std::string &file_name, const std::vector<std::string>& output_vector) {
    auto log = std::async(std::launch::async,
                                output_to_console,
                                output_vector);
    log.get();

    if(is_output_to_first_file) {
        auto file1 = std::async(std::launch::async,
                                      output_to_file,
                                      file_name, output_vector);
        file1.get();
    }

    else {
        auto file2 = std::async(std::launch::async,
                                      output_to_file,
                                      file_name, output_vector);
        file2.get();
    }

    is_output_to_first_file = !is_output_to_first_file;

//    output_to_console(output_vector);
//    output_to_file(file_name, output_vector);
}

void OutputHandler::output_to_console(const std::vector<std::string>& output_vector) {
    std::string c_output = "bulk: ";

    for(const std::string& string: output_vector)
        c_output += string + ", ";

    c_output.pop_back();
    c_output.pop_back();

    std::cout << c_output << std::endl;
}

void OutputHandler::output_to_file(const std::string &file_name, const std::vector<std::string>& output_vector) {
    std::string new_file_name = "bulk" + file_name;

    while(true){
        std::ifstream ifstream((new_file_name + ".log").c_str());

        if(ifstream.good())
            new_file_name += "_";
        else
            break;
    }

    new_file_name += ".log";

    std::fstream fstream{new_file_name, fstream.binary | fstream.trunc | fstream.out};

    if (!fstream.is_open())
        std::cout << "failed to open " << new_file_name << '\n';
    else
    {
        for(const std::string& string: output_vector){
            fstream.write(string.c_str(), sizeof(string.c_str()));
        }
    }
}

void OutputHandler::update(const std::string &file_name, const std::vector<std::string> &output_vector) {
    output_list(file_name, output_vector);
}

OutputHandler::OutputHandler()
    :is_output_to_first_file(true){

}

OutputHandler &OutputHandler::get_instance() {
    static OutputHandler instance;

    return instance;
}