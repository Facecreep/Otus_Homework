//
// Created by Faceecreep on 17.04.2025.
//

#include "BulkHandler.h"

BulkHandler::BulkHandler(int bulk_size)
:bulk_size(bulk_size),
is_in_dynamic_bulk(false){
}
BulkHandler::~BulkHandler()= default;

void BulkHandler::add_to_bulk(const std::string &string) {
    if (string == "{"){
        deepen_dynamic_bulk();
        return;
    }

    if (string == "}"){
        shallow_dynamic_bulk();
        return;
    }

    if(bulk_container.empty()){
        start_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
    }

    bulk_container.push_back(string);

    if(!is_in_dynamic_bulk && bulk_container.size() == bulk_size){
        end_bulk();
    }
}

void BulkHandler::deepen_dynamic_bulk() {
    if(!is_in_dynamic_bulk){
        is_in_dynamic_bulk = true;

        end_bulk();
    }

    dynamic_bulk_depth++;

}

void BulkHandler::shallow_dynamic_bulk() {
    dynamic_bulk_depth--;

    if(dynamic_bulk_depth == 0){
        is_in_dynamic_bulk = false;

        end_bulk();
    }
}

void BulkHandler::end_bulk() {
    if(bulk_container.empty())
        return;

    OutputHandler::output_to_file(
            "bulk" + std::to_string(start_time) + ".log",
            bulk_container
            );

    bulk_container.clear();
}



