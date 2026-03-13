//
// Created by sloth on 3/14/26.
//
#include "../include/database/database.h"

class Database{
    std::string connectionString;

public:
    Database(
        const int &port,
        const std::string& host,
        const std::string& dbName,
        const std::string& userName,
        const std::string& password) {
        this->connectionString = host + ":" + std::to_string(port)+":" + dbName+ ":"+ userName + ":" + password;
    }

    [[nodiscard]] const std::string& getConnectionString() const {return this->connectionString;}

};
