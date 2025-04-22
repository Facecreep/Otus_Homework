#include "async.h"
#include "BulkHandler.h"

namespace async {

handle_t connect(std::size_t bulk) {
    return new BulkHandler(bulk);

    return nullptr;
}

void receive(handle_t handle, const char *data, std::size_t size) {
    BulkHandler* bulk_handle = static_cast<BulkHandler*>(handle);

    for(size_t i = 0; i < size; i++, data++){
        bulk_handle->add_to_bulk(data);
    }

    std::cout << "here" << std::endl;

    auto map = bulk_handle->get_bulk_map();

    for(std::map<std::string, std::vector<std::string>>::iterator iterator = map.begin();
            iterator != map.end();
            iterator++){
        std::cout << iterator->first << std::endl;
    }
}

void disconnect(handle_t handle) {
}

}
