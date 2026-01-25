//
// Created by sloth on 1/25/26.
//

#ifndef POCKETLOG_BASE_MODEL_H
#define POCKETLOG_BASE_MODEL_H
#include <string>
#include <chrono>

class BaseModel {
private:
    std::string id;
    std::time_t created_at;
    std::time_t update_at ;

};

#endif //POCKETLOG_BASE_MODEL_H
