cmake_minimum_required(VERSION 4.1)
project(PocketLog CXX)
add_executable(pocket_log
        main.cpp
        dao/transaction.cpp
        dao/transaction.h
        util/date_time.h)
