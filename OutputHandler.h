//
// Created by Faceecreep on 17.04.2025.
//

#ifndef HELLOWORLD_OUTPUTHANDLER_H
#define HELLOWORLD_OUTPUTHANDLER_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class OutputHandler {
public:
    static void output_to_file(const std::string &file_name, std::vector<std::string> output_vector);

private:

};


#endif //HELLOWORLD_OUTPUTHANDLER_H
