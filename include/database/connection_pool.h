#pragma once

#include <pqxx/pqxx>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

class ConnectionPool {
private:
    std::queue<std::unique_ptr<pqxx::connection>> pool;
    std::mutex mutex_;
    std::condition_variable condition;

    int max_connections;
    std::string conn_string;

public:
    ConnectionPool(const std::string& conn_string, int size);

    std::unique_ptr<pqxx::connection> acquire();

    void release(std::unique_ptr<pqxx::connection> conn);
};