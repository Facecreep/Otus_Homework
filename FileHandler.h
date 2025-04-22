//
// Created by Faceecreep on 05.04.2025.
//

#ifndef UNTITLED_FILEHANDLER_H
#define UNTITLED_FILEHANDLER_H

#include <vector>
#include <string>

class FileHandler {
public:
    static void write_to_file(std::vector<std::vector<std::string>> object_data);
    static std::vector<std::vector<std::string>> load_from_file();
};


#endif //UNTITLED_FILEHANDLER_H
