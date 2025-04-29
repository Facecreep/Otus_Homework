//
// Created by Faceecreep on 29.04.2025.
//

#ifndef HELLOWORLD_OBSERVER_H
#define HELLOWORLD_OBSERVER_H

#include <string>
#include <vector>

class Observer {
public:
    virtual void update(const std::string &file_name, const std::vector<std::string>& output_vector) = 0;
};


#endif //HELLOWORLD_OBSERVER_H
