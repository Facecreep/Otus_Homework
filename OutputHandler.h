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

#include "Observer.h"

class OutputHandler : public Observer {
public:
    OutputHandler(OutputHandler const&) = delete;
    void operator=(OutputHandler const&) = delete;

    static OutputHandler& get_instance();

    void update(const std::string &file_name, const std::vector<std::string>& output_vector) override;

private:
    OutputHandler();

    void output_list(const std::string &file_name, const std::vector<std::string>& output_vector);
    void output_to_console(const std::vector<std::string>& output_vector);
    void output_to_file(const std::string &file_name, const std::vector<std::string>& output_vector);
};


#endif //HELLOWORLD_OUTPUTHANDLER_H
