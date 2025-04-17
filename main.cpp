#include "lib.h"

#include <iostream>
#include <stdio.h>

#include "BulkHandler.h"

int main(int argc, char **argv) {
	if(argc != 2)
	    throw std::invalid_argument( "Bulk size was not recieved" );

	size_t bulk_size = *argv[1] - '0';

    BulkHandler bulkHandler(bulk_size);


    while(true){
        std::string command;

        std::cin >> command;

        if(command == "eof")
            break;

        bulkHandler.add_to_bulk(command);
    }

	return 0;
}
