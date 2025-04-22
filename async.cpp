#include "async.h"
#include "BulkHandler.h"

namespace async {

handle_t connect(std::size_t bulk) {
    return new BulkHandler(bulk);

    return nullptr;
}

void receive(handle_t handle, const char *data, std::size_t size) {
    BulkHandler* bulk_handle = static_cast<BulkHandler*>(handle);

    std::string command;
    for(size_t i = 0; i < size; i++, data++){
        if(*data != '\n'){
            command.push_back(*data);
        }
        else if(command != ""){
            bulk_handle->add_to_bulk(command);
            command = "";
        }
    }

    if(command != "")
        bulk_handle->add_to_bulk(command);
}

void disconnect(handle_t handle) {
    BulkHandler* bulk_handle = static_cast<BulkHandler*>(handle);

    bulk_handle->force_end_bulk();
}

}
