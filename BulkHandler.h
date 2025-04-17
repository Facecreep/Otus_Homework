//
// Created by Faceecreep on 17.04.2025.
//

#ifndef HELLOWORLD_BULKHANDLER_H
#define HELLOWORLD_BULKHANDLER_H

#include <vector>
#include <string>
#include <chrono>

#include "OutputHandler.h"

class BulkHandler {
public:
    BulkHandler(int bulk_size);
    ~BulkHandler();

    void add_to_bulk(const std::string &string);

private:
    size_t bulk_size;

    bool is_in_dynamic_bulk;
    int dynamic_bulk_depth;

    int start_time;

    std::vector<std::string> bulk_container;

    void end_bulk();
    void deepen_dynamic_bulk();
    void shallow_dynamic_bulk();
};


#endif //HELLOWORLD_BULKHANDLER_H
