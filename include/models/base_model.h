//
// Created by sloth on 1/25/26.
//

#ifndef POCKETLOG_BASE_MODEL_H
#define POCKETLOG_BASE_MODEL_H
#include <string>
#include <chrono>

class BaseModel {
protected:
    uint64_t id;
    std::time_t created_at;
    std::time_t update_at;

public:
    BaseModel();

    virtual ~BaseModel() = default;

    BaseModel(uint64_t _id, std::time_t _created_at, std::time_t _update_at);

    uint64_t getId() const;

    std::time_t getCreatedAt() const;

    std::time_t getUpdatedAt() const;

    void setId(uint64_t _id);

    void setCreatedAt(std::time_t _created_at);

    void setUpdateAt(std::time_t _update_at);

    void touch();

protected:
    static const std::string timeToStr(std::time_t _time);

    static const std::time_t strToTime(std::string _time);
};

#endif //POCKETLOG_BASE_MODEL_H
