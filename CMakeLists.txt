cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(async VERSION ${PROJECT_VESRION})

add_library(async SHARED Observer.h BulkHandler.cpp BulkHandler.h OutputHandler.cpp OutputHandler.h async.cpp async.h)
add_executable(async_cli main.cpp BulkHandler.cpp BulkHandler.h OutputHandler.cpp OutputHandler.h async.cpp async.h)

set_target_properties(async PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

set_target_properties(async PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(async PROPERTIES PUBLIC_HEADER async.h)
target_include_directories(async PRIVATE .)
include(GNUInstallDirs)

install(TARGETS async
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})