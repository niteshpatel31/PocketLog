//
// Created by sloth on 1/26/26.
//

#include "../../include/models/base_model.h"

BaseModel::BaseModel() : id(random()),
                         created_at(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
                         update_at(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())) {
}

BaseModel::BaseModel(uint64_t _id, std::time_t _created_at, std::time_t _update_at) : id(_id), created_at(_created_at),
    update_at(_update_at) {
}

uint64_t BaseModel::getId() const { return this->id; }
std::time_t BaseModel::getCreatedAt() const { return this->created_at; }
std::time_t BaseModel::getUpdatedAt() const { return this->update_at; }

void BaseModel::setId(uint64_t _id) { id = _id; }
void BaseModel::setCreatedAt(std::time_t _created_at) { this->created_at = _created_at; }
void BaseModel::setUpdateAt(std::time_t _update_at) { this->update_at = _update_at; }

void BaseModel::touch() { this->update_at = std::time(nullptr); }

std::string BaseModel::timeToStr(const std::time_t &_time) {
    std::chrono::time_point tp = std::chrono::system_clock::from_time_t(_time);
    return std::format("{:%Y-%m-%d %H:%M:%S}", tp);
}

std::time_t BaseModel::strToTime(const std::string &_time) {
    std::tm tm{}; // creating ptr without memory is worthless leads to -> SIGSEGV 139
    std::istringstream ss{_time};
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return (ss.fail()) ? 0 : std::mktime(&tm);
}
