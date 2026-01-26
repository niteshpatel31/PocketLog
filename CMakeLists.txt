cmake_minimum_required(VERSION 4.1)
project(PocketLog CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS ON)

find_package(OpenSSL REQUIRED)

add_executable(pocket_log
        src/main.cpp
        include/models/transaction.h
        include/utils/time_util.h
        include/models/user.h
        src/config/config.cpp
        src/models/transaction.cpp
        include/models/base_model.h
        include/models/category.h
        src/models/base_model.cpp
        src/utils/time_util.cpp
        src/models/user.cpp
)

#target_compile_definitions(pocket_log PRIVATE CROW_ENABLE_SSL)
target_precompile_headers(pocket_log PRIVATE include/models/transaction.h include/models/user.h include/utils/DateTimeHelper.h)

target_link_libraries(pocket_log PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
        pthread
)