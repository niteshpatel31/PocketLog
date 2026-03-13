//
// Created by sloth on 3/14/26.
//

#include "../include/database/connection_pool.h"

ConnectionPool::ConnectionPool(const std::string &conn_string, int size)
    :conn_string(conn_string), max_connections(size)
{

}

std::unique_ptr<pqxx::connection> ConnectionPool::acquire() {

}

void ConnectionPool::release(std::unique_ptr<pqxx::connection> conn) {

}
