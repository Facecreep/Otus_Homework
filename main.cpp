#include "lib.h"

#include <iostream>
#include <stdio.h>

#include "BulkHandler.h"
#include "OutputHandler.h"

int main(int argc, char **argv) {
	if(argc != 2)
	    throw std::invalid_argument( "Bulk size was not recieved" );

	size_t bulk_size = *argv[1] - '0';

    BulkHandler bulk_handler(bulk_size);
    bulk_handler.add_observer(&OutputHandler::get_instance());

    while(true){
        std::string command;

        std::cin >> command;

        if(command == "eof"){
            bulk_handler.force_end_bulk();
            break;
        }

        bulk_handler.add_to_bulk(command);
    }

	return 0;
}
