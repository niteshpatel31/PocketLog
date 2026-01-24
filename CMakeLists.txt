cmake_minimum_required(VERSION 4.1)
project(PocketLog CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

add_executable(pocket_log
        main.cpp
        dao/transaction.cpp
        dao/transaction.h
        util/date_time.h)

target_compile_definitions(pocket_log PRIVATE CROW_ENABLE_SSL)

target_link_libraries(pocket_log PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
        pthread
)